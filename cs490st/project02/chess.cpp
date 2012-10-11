#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <dlfcn.h>

#include <map>
#include <signal.h>
#include <stdio.h>

using namespace std;

int (*original_pthread_create)(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*) = NULL;
int (*original_pthread_join)(pthread_t, void**) = NULL;
int (*original_pthread_mutex_lock)(pthread_mutex_t*) = NULL;
int (*original_pthread_mutex_unlock)(pthread_mutex_t*) = NULL;



int firstRun = 1;
int doExit = 0;

pthread_mutex_t GL;

int currentThread = 0; // currently running thread id

struct ThreadStruct {
    int id;
    int locked; // 0 = unlocked, 1 = locked
    int status; // 0 = terminated, 1 = running, 2 = waiting
};

map<int, ThreadStruct*> threads;
map<pthread_mutex_t*, ThreadStruct*> mutexes;
map<pthread_t*, int> threadids;

int mainThreadId = 0;

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

    original_pthread_mutex_lock(&GL);

    void* ret = thread_arg.start_routine(thread_arg.arg);

    original_pthread_mutex_unlock(&GL);

    puts("end of thread_main");
    doExit = 1;

    currentThread = mainThreadId;

    return ret;
}

extern "C"
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void*), void *arg)
{
    puts("pthread_create()");
    
    initialize_original_functions();

    if (firstRun == 1)
    {
        firstRun = 0;
        original_pthread_mutex_lock(&GL);
        
        currentThread = (int)pthread_self();

        mainThreadId = currentThread;
    }

    struct Thread_Arg *thread_arg = (struct Thread_Arg*)malloc(sizeof(struct Thread_Arg));
    thread_arg->start_routine = start_routine;
    thread_arg->arg = arg;

    int ret = original_pthread_create(thread, attr, thread_main, thread_arg);

    // TODO
    ThreadStruct *ts = new ThreadStruct();
    ts->id = (int)pthread_self();
    ts->locked = 0;
    ts->status = 1; // running
    
    threads[(int)pthread_self()] = ts;
    
    //original_pthread_mutex_lock(&GL);
    
    // threadids[thread] = (int)pthread_self();
    
    ts = new ThreadStruct();
    ts->id = (int)*thread;
    ts->locked = 0;
    ts->status = 1; // running
    
    threads[(int)*thread] = ts;

    threadids[thread] = (int)*thread;

    return ret;
}

extern "C"
int pthread_join(pthread_t joinee, void **retval)
{
    puts("pthread_join()");
    
    initialize_original_functions();

    // TODO
    int ret = 0;
    while ((ret = pthread_kill(joinee, 0)) == 0 &&
           doExit == 0)
    {
        //original_pthread_mutex_unlock(&GL);        
        sched_yield();
        //original_pthread_mutex_lock(&GL);
    }
    
    int tid = threadids[&joinee];
    
    //yThreadStruct *ts = threads[tid];
    //ts->status = 0; // terminated

    return ret; // return original_pthread_join(joinee, retval);
}

extern "C"
int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    puts("pthread_mutex_lock()");
    
    initialize_original_functions();

    // TODO
    int ret = 0;
    while ((ret = pthread_mutex_trylock(mutex)) != 0)
    {
        ThreadStruct *ts = threads[(int)pthread_self()];
        ts->status = 2; // waiting
    
        //original_pthread_mutex_unlock(&GL);        
        sched_yield();
        //original_pthread_mutex_lock(&GL);
    }
    
    ThreadStruct *ts = threads[(int)pthread_self()];
    ts->status = 1; // running

    ts->locked = 1;
    
    mutexes[mutex] = ts;

    return ret; // return original_pthread_mutex_lock(mutex);
}

extern "C"
int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    puts("pthread_mutex_unlock()");
    
    initialize_original_functions();

    // TODO
    ThreadStruct *ts = mutexes[mutex];
    ts->status = 1; // running
    ts->locked = 0;

    return original_pthread_mutex_unlock(mutex);
}

extern "C"
int sched_yield(void)
{
    puts("sched_yield()");
    
    initialize_original_functions();
    
    // TODO
    original_pthread_mutex_unlock(&GL);
    
    map<int, ThreadStruct*>::iterator iter;
    for (iter = threads.begin(); iter != threads.end(); ++iter)
    {
        ThreadStruct* curr = iter->second;
        if (curr->id != currentThread &&
            curr->status >= 1) // running
        {
            currentThread = curr->id;
            curr->status = 1; // running
            
            // puts("context switch");
            fprintf (stderr, "context switch to %d\n", curr->id);

            
            break;
        }
    }
    
    while (currentThread != (int)pthread_self())
    {
        // sleep
    }
    
    original_pthread_mutex_lock(&GL);
    
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
