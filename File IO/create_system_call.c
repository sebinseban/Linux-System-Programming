// The combination of O_WRONLY | O_CREAT | O_TRUNC will create a new file if it does not exist.
// The combination is so common that a system call called creat() is provided just for this purpose.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main()
{
    int fd;

    fd = creat("/workspaces/Linux-System-Programming/File IO/hello.c", 0644);
    printf("Error code: %d\n", errno);
    if (fd < 0)
    {
        perror("");
        exit(1);
    }
    else
    {
        printf("File created successfully using creat().  \n");
    }
}
