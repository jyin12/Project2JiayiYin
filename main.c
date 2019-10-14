#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"
#include "shell.c"

//starts shell
int main(int argc, char **argv) {

    //char *s = "ls -al . <in.txt.> out.txt | grep . | cd work"; //tester

    char *a;
    char **b;
    int stat;
    do{
        printf("myShell> ");
        a = userInput();
        b = parseSpace(a);
        stat = processCommand(b);
        free(a);
        free(b);
    } while(stat);
    return 0;
}