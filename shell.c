//
// Created by Jiayi Yin on 10/5/2019.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

//builtin commands (extras)

char *commandList[] = {"cd", "help", "exit"};
int (*func[])(char**) = {&currDir, &dirHelp, &processExit};

//function implementation
char *userInput(){
    char input[1000];
    int size = sizeof(input);
    char *buf = malloc(sizeof(char) * size); //increases the size for input[]
    int i, pos = 0;
    while(1) {
        i = getchar(); //reads the character user input
        if (i == '\n' || i == EOF) { //tell if the user input has an end or hit returned key
            buf[pos] = '\0';
            return buf;
        } else
            buf[pos] = i;
        pos++;
        if (pos >= size) {
            buf = realloc(buf, size); //increases the size if the buf exceeds the given size
            size += sizeof(input);
            if (!buf) { //size error
                fprintf(stderr, "User Input: Allocation Error\n");
                exit(0);
            }
        }
    }
}

char **parseSpace(char *word){
    int size = 100;
    int pos = 0;
    char **tokens = malloc(size * sizeof(char*));
    if(!tokens){
        fprintf(stderr, "Allocation error\n");
        exit(0);
    }
    char *token = strtok(word, " \t\r\n\a");
    while(token != NULL){ //checks for delimiters until the end of the word
        tokens[pos] = token; //store the words into tokens[] and pos increase as there are words adding into tokens[]
        pos++;
        if(pos >= size){ //increase memory size if the pos is bigger than size
            size += 100;
            tokens = realloc(tokens, size * sizeof(char*));
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[pos] = NULL;
    return tokens;
}

int forkPipe(char **forks){
    pid_t pid;
    pid_t pid2;
    int i;
    pid = fork(); //receive the pid (child)
    if(pid < 0) { //error in forking
        perror("ERROR forking");
        //exit(0);
    }
    else if(pid == 0) { //child process
        //pid2 = getpid();
        //printf("Child pid: %d\n", pid2); //tester
        if(execvp(forks[0], forks) == -1)
            //perror("error in child"); //tester
            perror("myShell");
        exit(0);
    }
    else{ //parent process
        while(!WIFEXITED(i) && !WIFSIGNALED(i)) {
            pid2 = wait(&i); //wait for child terminate
            //printf("Parent: child exit success\n"); //tester
        }
        printf("Parent finished\n");
    }
    return 1;
}

int processExit(char **input){
    return 0;
}

int currDir(char **input){
    if(input[1] == NULL)
        fprintf(stderr, "Too few argument for \"%s\"\n", *input);
    else{
        if(chdir(input[1]) != 0)
            perror("myShell");
    }
    return 1;
}

int dirHelp(char **input){
    FILE *fp;
    char c;
    fp = fopen("dirHelp", "r");
    c = fgetc(fp);
    if(fp == NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    return 1;
}

int processCommand(char **input){
    if(input[0] == NULL) //if user hit 'enter' on accident
        return 1;
    for(int i = 0; i < (sizeof(commandList) / sizeof(char *)); i++){ //checks the command list to check if user's input was valid
        if(strcmp(input[0], commandList[i]) == 0)
            return (*func[i])(input);
    }
    return forkPipe(input);


}