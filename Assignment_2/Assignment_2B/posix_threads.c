#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int global_count = 0;
//using namespace std;
#define NUM_THREADS 2

void *increment(void *threadid)
{
    int local_count = 0; 
    int *result = malloc(sizeof(int)); //allocate memory
    
    for (int j = 0; j < 69; j++)
    {
        global_count++;
        local_count++;
    }
    *result = local_count; 
    return (void*) result;
}

int main()
{
    int* res;
    pthread_t threads[NUM_THREADS];
    int rc;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Thread %d: \n",i+1);
        rc= pthread_create(&threads[i], NULL, increment, (void *)i); // Create thread with  pointer variable id=&threads[i] and the function to be executed is increment
        if (rc)
        {
            printf("Error:unable to create thread, %d\n", rc);
            exit(-1);
        }
        pthread_join(threads[i], (void**) &res); // join thread and return pointer top opintervariable res 
        printf("global count: %d \n local count: %d \n\n", global_count, *res);
        free(res); //free allocated memory
    }

    return 0;
}
