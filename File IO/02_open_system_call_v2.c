//implementing the open() system call in linux programming

//will work without sys/types.h and sys/stat.h
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


//following code opens the file and stores the file descriptor in the variable fd
int main()
{
    int fd;
//the flags argument maybe bitwise ORed with the following constants: O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_EXCL, O_NOCTTY, O_TRUNC, and O_APPEND.
// while using O_CREAT, the third argument is the file mode. Must set the argument or results are undefined.
    //fd = open("/workspaces/Linux-System-Programming/File IO/sample.txt", O_RDONLY | O_CREAT, 0700);
    fd = open("/workspaces/Linux-System-Programming/File IO/sample.txt", O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);

//error checking , implement this also
    if (fd < 0)
    {
        perror(""); //for perror, no need to provide any default messsages, it will print standard error messages
        exit(1);
    }
    else
    {
        printf("file opened successfully\n");
    }

}
