#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

sem_t mutex;
bool running = true;
int var1 = 0;
int var2 = 0;

void *increment()
{

    while (running)
    {
        //wait
        sem_wait(&mutex);
        var1 = var1 + 1;
        var2 = var1;
        sem_post(&mutex);
    }
}

void *print()
{

    for (int i = 1; i <= 20; i++)
    {
        //wait
        sem_wait(&mutex);
        printf("%d: Number 1 is %d number 2 is %d  \n", i, var1, var2);
        sem_post(&mutex);
        usleep(100000);
    }
    running = false;
}

void main()
{
    sem_init(&mutex, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread2, NULL, print, NULL);
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&mutex);
}