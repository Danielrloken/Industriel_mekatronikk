#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <sys/times.h>

void busy_wait_delay(int seconds)
{
int i, dummy;
int tps = sysconf(_SC_CLK_TCK);
clock_t start;
struct tms exec_time;
times(&exec_time);
start = exec_time.tms_utime;
while( (exec_time.tms_utime - start) < (seconds * tps))
{
for(i=0; i<1000; i++)
{
dummy = i;
}
times(&exec_time);
}
}

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
	printf("a message 1 \n");
    //sleep(5);
    busy_wait_delay(5);
    printf("a message 2 \n");
	return NULL;
}


int main()
{
	pthread_t thread_id1;
    pthread_t thread_id2;
	pthread_create(&thread_id1, NULL, myThreadFun,NULL);
    pthread_create(&thread_id2, NULL, myThreadFun,NULL);
	pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
	exit(0);
}
