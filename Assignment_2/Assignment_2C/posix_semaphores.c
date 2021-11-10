#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *thread(void *arg)
{
    //wait
    sem_wait(&mutex);
    for (int i = 1; i <= 4; i++)
    {
        printf("Thread number %d \n", i);

        usleep(100000);
    }
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex, 0, 3);
    pthread_t t1, t2, t3, t4, t5;
    pthread_create(&t1, NULL, thread, NULL);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_create(&t3, NULL, thread, NULL);
    pthread_create(&t4, NULL, thread, NULL);
    pthread_create(&t5, NULL, thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    sem_destroy(&mutex);
    return 0;
}