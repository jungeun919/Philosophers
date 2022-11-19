#include <sys/time.h> // gettimeofday

int main()
{
	struct timeval mytime;

	gettimeofday(&mytime, NULL);
}
