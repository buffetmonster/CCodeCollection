#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 32

int main() {
    int f = open("/proc/lll-gpio", O_RDWR);
    printf("/proc/lll-gpio: %d\n", f);
    int loop=0;
    char buffer[BUFFER_SIZE];

    while (1) {
        ssize_t bytes_read = read(f, buffer, BUFFER_SIZE - 1);

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // Ensure null termination
            printf("%d : %s", loop, buffer); // Print received data
        } else if (bytes_read == 0) {
            printf("End of file reached\n");
            break;
        } else {
            printf("Error reading from file\n");
            break;
        }
        loop++;
        if (loop > 20){
            break;
        }

    }

    close(f);
    return 0;
}