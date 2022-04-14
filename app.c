#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "cli.h"


static void rootFunc(int argc, char **argv) {
    int opt;

    while ((opt=getopt(argc, argv, "abc")) != -1) {
        switch (opt)
        {
        case 'a':
            printf("Option a was provided\n");
            break;
        case 'b':
            printf("Option b was provided\n");
            break;
        case 'c':
            printf("Option c was provided\n");
            break;
        }
    }
}

static void subFunc(int argc, char **argv) {
    int opt;

    while ((opt=getopt(argc, argv, "def")) != -1) {
        switch (opt)
        {
        case 'd':
            printf("Option b was provided\n");
            break;
        case 'e':
            printf("Option n was provided\n");
            break;
        case 'f':
            printf("Option t was provided\n");
            break;
        }
    }
}

static void sub2Func(int argc, char **argv) {
    int opt;

    while ((opt=getopt(argc, argv, "ghi")) != -1) {
        switch (opt)
        {
        case 'g':
            printf("Option b was provided\n");
            break;
        case 'h':
            printf("Option n was provided\n");
            break;
        case 'i':
            printf("Option t was provided\n");
            break;
        }
    }
}

static void sub3Func(int argc, char **argv) {
    int opt;

    while ((opt=getopt(argc, argv, "jkl")) != -1) {
        switch (opt)
        {
        case 'j':
            printf("Option b was provided\n");
            break;
        case 'k':
            printf("Option n was provided\n");
            break;
        case 'l':
            printf("Option t was provided\n");
            break;
        }
    }
}


int main(int argc, char **argv)
{

    command_t *rootCmd = calloc(1, sizeof(command_t));
    command_t *subCmd = calloc(1, sizeof(command_t));
    command_t *sub2Cmd = calloc(1, sizeof(command_t));
    command_t *sub3Cmd = calloc(1, sizeof(command_t));

    initCommand(rootCmd, "root", rootFunc);
    initCommand(subCmd, "sub", subFunc);
    initCommand(sub2Cmd, "sub2", sub2Func);
    initCommand(sub3Cmd, "sub3", sub3Func);

    addCommand(subCmd, sub2Cmd);
    addCommand(subCmd, sub3Cmd);
    addCommand(rootCmd, subCmd);
    executeCommand(rootCmd, argc, argv);

    return 0;
}
