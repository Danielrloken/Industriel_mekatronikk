#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int var1 = 0;
int var2 = 0;
int running = 1;
void *thread1(void *arg)
{
    //wait
    
    while (running)
    {
        sem_wait(&mutex);
        var1 = var1 + 1;
        var2 = var1;
        sem_post(&mutex);
        usleep(100000);
    }
    
}

void *thread2(void *arg)
{
    //wait
    
    for (int i = 1; i <= 20; i++)
    {
        sem_wait(&mutex);
        printf("Number 1 is %d number 2 is %d  \n", var1, var2);
        sem_post(&mutex);
        usleep(100000);

    }
    
    running = 0;
}
int main()
{
    sem_init(&mutex, 0, 1); 
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    sem_destroy(&mutex);
    return 0;
}