#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int f = open("/proc/lll-gpio", O_RDWR);
	printf("/proc/lll-gpio:%d\n",f);
	while (1)
	{
		printf("On\n");
		write(f, "21,1", 4);
		usleep(500000);
                printf("Off\n");
		write(f, "21,0", 4);
		usleep(500000);
	}
}
//note we can also access this another way:
//echo "21,1" > /proc/lll-gpio
//echo "21,0" > /proc/lll-gpio
//cat /proc/lll-gpio
