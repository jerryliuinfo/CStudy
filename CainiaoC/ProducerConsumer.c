#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h> // 包含 usleep

#define MAX_ITEMS 20

typedef struct
{
    int items[MAX_ITEMS];
    int count;
    // 表示下一个要插入新元素的位置。当一个新元素被添加到队列中时，in 指向的位置就是新元素应该放置的位置。在插入操作之后，in 的值通常会更新，指向下一个可能的插入位置。
    int in;
    // 表示下一个要移除元素的位置。当从队列中取出一个元素时，out 指向的位置就是应该被移除的元素的位置。在移除操作之后，out 的值也会更新，指向下一个可能的移除位置。
    int out;
    pthread_mutex_t lock;
    pthread_cond_t can_produce;
    pthread_cond_t can_consume;
} queue_t;

void queue_init(queue_t *q)
{
    q->count = 0;
    q->in = 0;
    q->out = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->can_produce, NULL);
    pthread_cond_init(&q->can_consume, NULL);
}

void queue_destroy(queue_t *q)
{
    pthread_mutex_destroy(&q->lock);
    pthread_cond_destroy(&q->can_produce);
    pthread_cond_destroy(&q->can_consume);
}

void *producer(void *arg)
{
    queue_t *q = (queue_t *)arg;
    int item;
     unsigned int seed; // 种子
    for (size_t i = 0; i < MAX_ITEMS; i++)
    {
        item = i;
        pthread_mutex_lock(&q->lock);
        while (q->count >= MAX_ITEMS)
        {
            // 队列满了，等待被唤醒(q->can_producer 发生改变时被唤醒)，此时   q->items[q->in] = item; 不会被执行
            pthread_cond_wait(&q->can_produce, &q->lock);
        }
        q->items[q->in] = item;
        q->in = (q->in + 1) % MAX_ITEMS;
        q->count++;
        printf("Produced:%d\n", item);
        // 通知消费者 &q->can_consumer
        pthread_cond_signal(&q->can_consume);
        pthread_mutex_unlock(&q->lock);

        seed = 0;
        // usleep((rand() % 1000) * 1000);
        //rand_r 相比 rand，会线程安全
        usleep((rand_r(&seed) % 1000) * 1000);
    }
    return NULL;
}

void *consumer(void *arg)
{
    queue_t *q = (queue_t *)arg;
    int item;
    for (size_t i = 0; i < MAX_ITEMS; i++)
    {
        pthread_mutex_lock(&q->lock);
        // 队列空了，等待
        while (q->count == 0)
        {
            // 等待被唤醒(q->can_consumer 发生改变时被唤醒, 生产者会唤醒这个值)
            pthread_cond_wait(&q->can_consume, &q->lock);
        }
        item = q->items[q->out];
        q->out = (q->out + 1) % MAX_ITEMS;
        q->count--;
        printf("Consumed:%d\n", item);
        // 通知生产者 q->can_producer)
        pthread_cond_signal(&q->can_produce);
        pthread_mutex_unlock(&q->lock);
        usleep((rand() % 1000) * 1000);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t prod, cons;
    queue_t q;

    queue_init(&q);

    pthread_create(&prod, NULL, producer, &q);
    pthread_create(&cons, NULL, consumer, &q);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    queue_destroy(&q);

    return 0;
}
