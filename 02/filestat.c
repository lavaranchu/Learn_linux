#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    char timebuf[100];

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];

    if (lstat(path, &fileStat) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    printf("File Path: %s\n", path);

    printf("File Type: ");
    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    printf("Size: %ld bytes\n", (long)fileStat.st_size);

    struct tm *timeinfo = localtime(&fileStat.st_mtime);
    if (timeinfo != NULL) {
        strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("Last Modified: %s\n", timebuf);
    } else {
        printf("Last Modified: (cannot read time)\n");
    }

    return 0;
}
