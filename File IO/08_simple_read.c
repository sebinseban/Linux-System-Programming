

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char buffer[128];
    int bytes_read;

    bytes_read = read(0, buffer, 128);
    if (bytes_read == -1)
    {
        perror("");
        write(2, "A read error has occurred on file descriptor 0\n", 45); //printing to stderr
        exit (1);
    }

    if ( (write (1, buffer, bytes_read)) != bytes_read)
    {
        perror("");
        write(2, "A write error has occurred on file descriptor 1\n", 45);
        exit(1);
    }

    exit(0);

}