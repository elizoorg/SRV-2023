#include <unistd.h>
#include <stdio.h>
int main()
{
    fflush(stdout);
    int pid = fork();
    if (pid != 0)
        printf("Parent: Nikita %d\n", getpid());
    else
        printf("Child: Eliseev I992 %d\n", getpid());
    fflush(stdout);
    sleep(20);
    return 0;
}