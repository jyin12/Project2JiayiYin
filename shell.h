//
// Created by Jiayi Yin on 9/29/2019.

#ifndef PROJECT2_SHELL_H
#define PROJECT2_SHELL_H

#endif //PROJECT2_SHELL_H

//function declaration
char *userInput();
char **parseSpace(char *word);
int forkPipe(char **forks);
int processExit(char **input);
int currDir(char **input);
int dirHelp(char **input);
int processCommand(char **input);







































/*
//used for redirections
#define REDIRECT_RIGHT '>'
#define REDIRECT_LEFT '<'

#define PIPE '|'
#define AMPERSAND '&'

//system status
#define WAITING 0
#define PROGRAM 1
#define ARGS 2
#define STDIN 3
#define STDOUT 4
#define READ_PIPE 5
#define READ_AMP 6

#define INPUT_BUFFER_SIZE 1000
#define CURRDIR_BUFFER_SIZE 1000
#define PATH_MAX 10000

//structs

typedef struct{
    unsigned int ampSign; //checks for ampersand signs
    pid_t pid; //gets the PID in forking
    char *progString; //program string
    char **argv; //system command execution
    int stdin; //stdin pipes
    int stdout; //stdout pipes
    int status; //corresponds to system status above
    struct Process *next; //list of piped processes
}Process;

//function declarations
unsigned int parseIndex(char *str, unsigned int cur, unsigned char parsed);   //Index of next non-space character
char **parseSpace(char *input, size_t size);   //puts args into char array
Process *processCommand(char *input, int size);   //takes in user's input and accounts processes commandline arg
int path(char *path, char executable);   //looks for path and if there is, it returns the path of executable
_Bool executable(char *path);    //checks if path is executable

void dirHelp();     //opens a list of internal commands that can be used ******


//My List of Codes
int userInput(char *input);
void parseSpace(char *input, char **parsed);    //parsing user's input commands
void printDirectory();      //prints out current directory (from file)
void forking(char **input);
void piping(char **input, char **parse);
int findPipe(char *input, char *piped);     //find out where piping is executed
int processExec(char **input);      //executes the commands
void history(char *str);*/


