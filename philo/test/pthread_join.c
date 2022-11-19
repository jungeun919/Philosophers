#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *routine(void *str)
{
	printf("thread function 실행 시작\n");
	for (int i = 1; i <= 5; i++)
	{
		usleep(1000 * 1000);
		printf("thread function 실행중 (%d/5)\n", i);
	}
	printf("thread function end\n");
	return (void *)(42);
}

int main()
{
	pthread_t thread;
	int result;

	if ((pthread_create(&thread, NULL, routine, NULL) != 0))
	{
		perror("pthread create error");
		exit(1);
	}

	pthread_join(thread, (void *)&result);
	
	printf("thread join 실행 후 => result: %d\n", result);
	printf("main end\n");
	return (0);
}
