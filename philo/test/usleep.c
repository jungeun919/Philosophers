#include <unistd.h> // usleep
#include <stdio.h>

int main()
{
	while (1)
	{
		printf("print per 1 second\n");
		usleep(1000 * 1000); // 1sec
	}
}
