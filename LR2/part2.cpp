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
    for (n = 0; n < 10; n++)
    {
        printf("I992 - 1st thread, TID %d - N povtora %d\n", thread_id1, n);
    }
}

void *long_thread2(void *notused)
{
    int m;
    for (m = 0; m < 10; m++)
    {
        printf("Eliseev Nikita - 2nd thread, TID %d - N povtora %d\n", thread_id1, m);
    }
}

int main()
{
    // Вариант 4. Приоритеты : 6 12 . Алгоритмы : RR RR
    printf("Prog threads PID %d \n", getpid());
    pthread_attr_init(&attr1);
    pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr1, SCHED_RR);
    attr1.param.sched_priority = 6;

    pthread_attr_init(&attr2);
    pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr2, SCHED_RR);
    attr2.param.sched_priority = 12;

    pthread_create(&thread_id1, &attr1, long_thread1, NULL);
    pthread_create(&thread_id2, &attr2, long_thread2, NULL);


    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
    return (1);
}