#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
    if( argc != 2 )
    {
        printf("\n File name missing\n");
        exit(1);
    }

int d,r,w;
int count;
char array[4096];
d=open(argv[1], O_RDONLY);

    if( d < 0 )
    {
        perror("cannot open file");
        exit(1);
    }
    else
    {
        r = read(d,array,4096);
        if(r > 0) //print the contents
        {
            write(1,array,sizeof(array));
        }
    }

	close(d);

exit(0);

}




