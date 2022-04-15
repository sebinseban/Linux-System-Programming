//a simple program to find the program name using variables

#include <stdio.h>
#include <errno.h>

extern char* __progname;
extern char* program_invocation_name;
extern char* program_invocation_short_name;

int main()
{
    
    printf("__progname : %s\n", __progname);
    printf("The program name is : %s\n", program_invocation_name);
    printf("program_invocation_short_name v: %s\n", program_invocation_short_name);

}