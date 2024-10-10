#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

