//this code snippet is to overcome the basic read functionality which can cause more than 5 errors

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
    int fd;
    fd = open("story.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("");
        printf("Error number: %d\n", errno);
        printf("File descriptor: %d\n", fd);
        exit(1);
    }
    else
    {
        printf("File opened successfully. File descriptor is %d\n", fd);

        //implementing read system call
        ssize_t bytes_read;
        unsigned long word;
        char buffer[100];
        int len = 100;
        while ( len != 0 && (bytes_read =  read(fd, &word , len)) != 0)
        {
            if (bytes_read == -1)
            {
                printf("Error number: %d\n", errno);
                if (errno == EINTR)
                     continue;
                perror("read() failed");
                break;

            }
            len -= bytes_read;
            word += bytes_read;
            printf("%lu\n", word);
        }


    }
}