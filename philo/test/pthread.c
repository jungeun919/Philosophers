#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *routine(void *str)
{
	for (int i = 1; i <= 5; i++)
	{
		usleep(1000 * 1000 * 2);
		printf("%s: ", (char *)str);
		printf("thread function 실행중 (%d/5)\n", i);
	}
	printf("thread function end\n");
	return (void *)(42);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;

	if ((pthread_create(&thread1, NULL, routine, "thread1") != 0))
	{
		perror("pthread create error");
		exit(1);
	}

	if ((pthread_create(&thread2, NULL, routine, "thread2") != 0))
	{
		perror("pthread create error");
		exit(1);
	}

	// pthread_detach(thread1);
	// pthread_detach(thread2);

	pthread_join(thread1, 0);
	pthread_join(thread2, 0);

	int s = 0;
	while (1)
	{
		printf("%d초 경과\n", s++);
		usleep(1000 * 1000);
	}

	printf("main end\n");
	return (0);
}
