//sebin sebastian
//02/04/2022
//Write a system program to implement your own version of cp command.


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fd_src, fd_dest;
    char buffer[4096];
    int bytes_read;
    if (argc < 3)
    {
        write(2, "Usage: cp <source> <destination>\n", 33);
        exit(1);
    }
    fd_src = open(argv[2], O_RDONLY);
    if (fd_src == -1)
    {
        write(2, "cp: ", 4);
        write(2, "No such file or directory\n", 26);
        exit(1);
    }
    fd_dest = open(argv[1], O_WRONLY |O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1)
    {
        write(2, "cp: ", 4);
        perror(argv[2]);
        exit(1);
    }

    while ( (bytes_read = read(fd_src, buffer, 4096)) > 0)
    {
        write(fd_dest, buffer, bytes_read);
    }
    close(fd_src);
    close(fd_dest);
    exit(0);
}