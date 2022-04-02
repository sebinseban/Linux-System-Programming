//sebin sebastian
//02/04/2022
//Write a system program to implement your own version of echo command.

#include <unistd.h>
#include <string.h>

int main( int argc, char* argv[])
{
    int i = 1;
    while (argv[i] != NULL)
    {
        write(1, argv[i], strlen(argv[i]));
        write(1, " ", 1);                   //put a space after each word
        i++;
    }
    write(1, "\n", 1);                       //put a new line at the end

}