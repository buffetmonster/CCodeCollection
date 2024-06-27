#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <stdbool.h>
#define IOCTL_SET_PIN _IOW('a', 1, int32_t*)
#define IOCTL_SET_VALUE _IOW('a', 2, int32_t*)
//NOTE: to run user space app:  sudo ./blink-led
//use pin 21:
//1: on
//0: off

int UserInputPio (){
    int fd;
    int32_t pin, value;

    printf("Enter the pin number: ");
    scanf("%d", &pin);
    printf("Enter the value (0 or 1): ");
    scanf("%d", &value);

    fd = open("/dev/lll-gpio", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }

    if (ioctl(fd, IOCTL_SET_PIN, (int32_t*)&pin) < 0) {
        perror("Failed to set the pin...");
        close(fd);
        return errno;
    }

    if (ioctl(fd, IOCTL_SET_VALUE, (int32_t*)&value) < 0) {
        perror("Failed to set the value...");
        close(fd);
        return errno;
    }

    printf("Pin set successfully\n");
    close(fd);  
}

int TogglePio (){
    int fd;
    static int32_t pin=21;
    int32_t value = false;
    unsigned int cycle = 6;
    printf("Pin value: %d\n",value);
    printf("Pin set: %d\n",pin);
    fd = open("/dev/lll-gpio", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }
    while (cycle){
      if (ioctl(fd, IOCTL_SET_PIN, (int32_t*)&pin) < 0) {
          perror("Failed to set the pin...");
          close(fd);
          return errno;
      }
  
      if (ioctl(fd, IOCTL_SET_VALUE, (int32_t*)&value) < 0) {
          perror("Failed to set the value...");
          close(fd);
          return errno;
    }
    cycle--;
    printf("Pin set successfully:%d\n", value);
    value=!value; //toggle
    }
    close(fd);  
}

int main() {
    //UserInputPio();
    TogglePio();
    return 0;
}
