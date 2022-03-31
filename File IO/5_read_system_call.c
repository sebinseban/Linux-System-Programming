//now that we have learned how to open a file, we can use it to read and write data using read() and write() system calls.

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //write code to open a file using system call
    //inorder to read, we need a file descriptor related to that file using open() system call
    int fd;
    fd = open("/workspaces/Linux-System-Programming/File IO/story.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("");
        printf("File descriptor: %d\n", fd);
        exit(1);
    }
    else
    {
        printf("File opened successfully. File descriptor is %d\n", fd);
    }

    //write code to read the file using read() system call
    //the read() system call reads up to the number of bytes specified in the second argument
    //the first argument is the file descriptor
    //the second argument is the buffer where the data is stored
    //the third argument is the number of bytes to be read
    //ssize_t read(int fd, void *buf, size_t len);

 /* there are so many drawbacks to using read() system call this
 way. so an advanced way with all error condition is written in the next
 program */
    char buffer[100];
    int bytes_read;

    bytes_read = read(fd, buffer, 100);
    printf("Bytes read: %d\n", bytes_read);
    if (bytes_read < 0)
    {
        perror("");
        printf("errno: %d\n", errno);
        exit(1);
    }
    else
    {
        printf("%s\n",buffer);
    }

}