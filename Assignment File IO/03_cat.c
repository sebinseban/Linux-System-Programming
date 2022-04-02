//sebin sebastian
//02/04/2022
//Write a system program to implement your own version of cat command.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main( int argc, char* argv[])
{
    if (argc < 2)
    {
        write(2, "Usage: cat <filename>\n", 24);
        exit(1);
    }
    int i = 1;
    while (argv[i] != NULL)
    {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            write(2, "cat: ", 5);
            write(2, argv[i] , strlen(argv[i]));
            write(2, " No such file or directory\n", 27);
            exit(1);
        }
        char buffer[4096];
        int bytes_read = read(fd, buffer, 4096);
        while (bytes_read > 0)
        {
            write(1, buffer, bytes_read);
            bytes_read = read(fd, buffer, 4096);
        }
        write(1, "\n", 1);
        close(fd);
        i++;
    }
}