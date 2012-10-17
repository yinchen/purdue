#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct QueueEntry {
    char* string;  
    int empty;
    int timestamp;
};

#define Q_SIZE 3
struct QueueEntry Q[Q_SIZE];
pthread_mutex_t Q_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t signal_mutex = PTHREAD_MUTEX_INITIALIZER;
int g_timestamp = 0;

void Q_init();
void Q_clear();
void Q_add(const char*);
void* thread1(void* arg);
void* thread2(void* arg);

int main()
{
    Q_init();

    pthread_t thread;
    pthread_create(&thread, NULL, thread2, NULL); 
    thread1(0);
    pthread_join(thread, NULL);

    return 0;
}

void* thread1(void* arg)
{
    Q_add("data 0");
    Q_add("data 1");
    Q_add("data 2");
    Q_add("data 3");
    Q_add("data 4");
    Q_clear();

    return NULL;
}

void* thread2(void* arg)
{
    Q_add("data 5");
    Q_add("data 6");
    Q_add("data 7");
    Q_add("data 8");
    Q_add("data 9");
    Q_clear();

    return NULL;
}

void Q_init()
{
    int i;
    for (i = 0; i < Q_SIZE; i++) {
        Q[i].string = 0;
        Q[i].empty = 1;
        Q[i].timestamp = 0;
    }
}

void Q_clear()
{
    Q_init();
}

int  Q_full()
{
    pthread_mutex_lock(&Q_mutex);
    int idx;
    int ret = 1;
    for (idx = 0; idx < Q_SIZE; idx++)
        if (Q[idx].empty) ret = 0;
    pthread_mutex_unlock(&Q_mutex);
    return ret;
}

void Q_discard_oldest()
{
    int discardidx;
    int discardts;
    int idx;
    pthread_mutex_lock(&Q_mutex);
    discardidx = 0;
    discardts = Q[0].timestamp;
    for (idx = 1; idx < Q_SIZE; idx++)
        if (discardts > Q[idx].timestamp) {
            discardidx = idx;
            discardts = Q[idx].timestamp;
        }

    fputs ("discard ", stdout);
    fputs (Q[discardidx].string, stdout);
    fputs ("\n", stdout);

    free(Q[discardidx].string);

    Q[discardidx].empty = 1;
    Q[discardidx].string = 0;
    Q[discardidx].timestamp = 0;
    pthread_mutex_unlock(&Q_mutex);
}


void Q_add(const char* s)
{
    if (Q_full())
        Q_discard_oldest();

    pthread_mutex_lock(&Q_mutex);
    
    int idx;
    for (idx = 0; idx < Q_SIZE; idx++) {
        if (Q[idx].empty) break;
    }

    Q[idx].empty = 0;
    Q[idx].timestamp = ++g_timestamp;
    Q[idx].string = strdup(s);

    fputs ("add ", stdout);
    fputs (Q[idx].string, stdout);
    fputs ("\n", stdout);

    pthread_mutex_unlock(&Q_mutex);
}
