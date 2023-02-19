#include <stdio.h>
#include <pthread.h>
#include <sys/neutrino.h>
#include <sched.h>
#include <process.h>
#include <unistd.h>
pthread_t thread_id1;
pthread_t thread_id2;
pthread_attr_t attr1;
pthread_attr_t attr2;
void *long_thread1(void *notused)
{
    int n;
    for (n = 0; n < 5; n++)
    {
        printf("I992 - 1st thread, TID %d - N povtora %d\n", thread_id1, n);
    }
}

void *long_thread2(void *notused)
{
    int m;
    for (m = 0; m < 5; m++)
    {
        printf("Eliseev Nikita - 2nd thread, TID %d - N povtora %d\n", thread_id1, m);
    }
}

int main()
{
    printf("Prog threads PID %d \n", getpid());
    pthread_attr_init(&attr1);
    pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr1, SCHED_FIFO);
    attr1.param.sched_priority = 2;

    pthread_attr_init(&attr2);
    pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
    attr2.param.sched_priority = 15;

    pthread_create(&thread_id1, &attr1, long_thread1, NULL);
    pthread_create(&thread_id2, &attr2, long_thread2, NULL);
    //TODO: Don't use sleep func . Use pthread_join instead. 
    sleep(20);
    return (1);
}