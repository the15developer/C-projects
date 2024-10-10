#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    pid_t pid;
    int x = 1;

    pid = fork(); 
    if (pid == 0) {  /* Child */
        printf("child : x=%d\n", ++x); 
	return 0;
    }

    /* Parent */
    printf("parent: x=%d\n", --x); 
    return 0;
}

