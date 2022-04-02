#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    if (write(1 , "Here is some data\n", 18) != 18)
    {
        perror("");
        write(2, "A write error has occurred on file descriptor 1\n", 45);
        exit(1);
    }
    write(2, "A write error has occurred on file descriptor 1\n ", 45);
}