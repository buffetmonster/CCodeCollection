#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

int GetProcessIdByName(const char* processName) {
    DIR *dir;
    struct dirent *entry;
    char path[512];

    dir = opendir("/proc");
    if (dir == NULL) {
        return -1; // Error opening directory
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a numerical directory (process ID)
        if (strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
            sprintf(path, "/proc/%s/cmdline", entry->d_name);
            FILE *file = fopen(path, "r");
            
            if (file) {
                char buffer[256];
                if (fgets(buffer, sizeof(buffer), file) != NULL) {
                    printf("File:%s %s\n", processName, buffer);
                    if (strstr(buffer, processName) != NULL) {
                        fclose(file);
                        closedir(dir);
                        return atoi(entry->d_name);
                    }
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
    return 0; // Process not found
}

int main() {
    int pid = GetProcessIdByName("dbus-server");
    if (pid > 0) {
        printf("Process ID found, killing it!: %d\n", pid);
        kill(pid,SIGKILL);
    } else {
        printf("Process not found.\n");
    }
    return 0;
}