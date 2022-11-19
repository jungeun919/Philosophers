#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *routine(void *str)
{
	pthread_t thread_id;

	thread_id = pthread_self();

	char *thread_name = (char *)str;

	int i = 0;
	while (i < 3)
	{
		printf("thread name : %s, thread id : %x\n", thread_name, (unsigned int)thread_id);
		i++;
		usleep(1000 * 1000);
	}
	return (NULL);
}

int main()
{
	pthread_t thread;
	
	char *p1 = "thread created";
	char *p2 = "thread main";

	if ((pthread_create(&thread, NULL, routine, (void *)p1)) != 0)
	{
		perror("pthread create error");
		exit(1);
	}

	routine((void *)p2);

	printf("created thread is : %x\n", (unsigned int)thread);
	printf("end\n");
	return (0);
}
