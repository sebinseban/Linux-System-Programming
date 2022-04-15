//use the environ variable to print all the environment variables

#include <stdio.h>

extern char** environ;

int main()
{
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}