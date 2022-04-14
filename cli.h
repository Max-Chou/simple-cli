#ifndef CLI_H_
#define CLI_H_
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "list.h"

#define SIZE 40

typedef struct command_ {
    char name[SIZE];
    int argc;
    char **argv;
    void (*func) (int argc, char **argv);
    struct command_ *parent;
    list_t *children;
} command_t;

void initCommand(command_t *cmd, char *name, void (*func)(int , char **));

void addCommand(command_t *parent, command_t *child);

void executeCommand(command_t *cmd, int argc, char **argv);


#endif