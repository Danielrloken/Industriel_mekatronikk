#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int global_count = 0;

int fork_counter(int i)
{
    int local_count = 0;
    // make two process which run same
    // program after this instruction
    printf("fork(): \n");
    fork();
    for (int j = 0; j < i; j++)
    {
        global_count++;
        local_count++;
    }
    printf("global count: %d \n local count: %d \n\n", global_count, local_count);
}

int vfork_counter(int i)
{
    int local_count = 0;
    printf("vfork(): \n");
    // make two process which run same
    // program after this instruction
    vfork();
    for (int j = 0; j < i; j++)
    {
        global_count++;
        local_count++;
    }
    printf("global count: %d \n local count: %d \n", global_count, local_count);
}
int main()
{
    vfork_counter(69);

    return 0;
}
