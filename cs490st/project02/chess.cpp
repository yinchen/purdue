#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <dlfcn.h>

#include <map>
#include <signal.h>

using namespace std;

int (*original_pthread_create)(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*) = NULL;
int (*original_pthread_join)(pthread_t, void**) = NULL;
int (*original_pthread_mutex_lock)(pthread_mutex_t*) = NULL;
int (*original_pthread_mutex_unlock)(pthread_mutex_t*) = NULL;


int firstRun = 1;

pthread_mutex_t GL;

struct ThreadStruct {
    int id;
    int status; // 0 = unlocked, 1 = locked
};

map<pthread_t*, int> threads; // 0 = running, 1 = waiting, -1 = terminated
map<pthread_mutex_t*, ThreadStruct*> mutexes;


static void initialize_original_functions();

struct Thread_Arg {
    void* (*start_routine)(void*);
    void* arg;
};

static
void* thread_main(void *arg)
{
    struct Thread_Arg thread_arg = *(struct Thread_Arg*)arg;
    free(arg);

    return thread_arg.start_routine(thread_arg.arg);
}

extern "C"
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void*), void *arg)
{
    initialize_original_functions();

    if (firstRun == 1)
    {
        firstRun = 0;
        pthread_mutex_lock(&GL); 
    }

    struct Thread_Arg *thread_arg = (struct Thread_Arg*)malloc(sizeof(struct Thread_Arg));
    thread_arg->start_routine = start_routine;
    thread_arg->arg = arg;

    int ret = original_pthread_create(thread, attr, thread_main, thread_arg);

    // TODO
    pthread_mutex_lock(&GL);
    threads[thread] = 0; // running

    return ret;
}

extern "C"
int pthread_join(pthread_t joinee, void **retval)
{
    initialize_original_functions();

    // TODO
    while (pthread_kill(joinee, 0) != 0)
    {
        pthread_mutex_unlock(&GL);        
        sched_yield();
        pthread_mutex_lock(&GL);
    }
    
    threads[&joinee] = -1; // terminated

    return original_pthread_join(joinee, retval);
}

extern "C"
int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    initialize_original_functions();

    // TODO
    while (pthread_mutex_trylock(mutex) != 0)
    {
        pthread_mutex_unlock(&GL);        
        sched_yield();
        pthread_mutex_lock(&GL);
    }
    
    ThreadStruct *ts = new ThreadStruct();
    ts->id = (int)pthread_self();
    ts->status = 1;
    
    mutexes[mutex] = ts;

    return original_pthread_mutex_lock(mutex);
}

extern "C"
int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    initialize_original_functions();

    // TODO
    ThreadStruct *ts = mutexes[mutex];
    ts->status = 0;

    return original_pthread_mutex_unlock(mutex);
}

extern "C"
int sched_yield(void)
{
    // TODO
    pthread_mutex_unlock(&GL);        
    /* select next available thread to execute */
    pthread_mutex_lock(&GL);
    
    return 0;
}

static
void initialize_original_functions()
{
    static bool initialized = false;
    if (!initialized) {
        initialized = true;

        original_pthread_create =
            (int (*)(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*))dlsym(RTLD_NEXT, "pthread_create");
        original_pthread_join = 
            (int (*)(pthread_t, void**))dlsym(RTLD_NEXT, "pthread_join");
        original_pthread_mutex_lock =
            (int (*)(pthread_mutex_t*))dlsym(RTLD_NEXT, "pthread_mutex_lock");
        original_pthread_mutex_unlock =
            (int (*)(pthread_mutex_t*))dlsym(RTLD_NEXT, "pthread_mutex_unlock");
    }
}
