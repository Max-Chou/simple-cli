#include "cli.h"


static int search_by_name(void *data, void *key) {
    command_t *cmd = (command_t *) data;
    if (strcmp(cmd->name, key) == 0) {
        return 0;
    } else {
        return -1;
    }
}

void initCommand(command_t *cmd, char *name, void (*func)(int , char **))
{
    strncpy(cmd->name, name, strlen(name));
    cmd->func = func;
    cmd->parent = NULL;
    cmd->children = calloc(1, sizeof(list_t));
    setMatchList(cmd->children, search_by_name);
}

void addCommand(command_t *parent, command_t *child)
{
    parent->children = addNodeList(parent->children, child);
    child->parent = parent;
}

void executeCommand(command_t *cmd, int argc, char **argv)
{
    // search subcommands
    command_t *nextcmd = (command_t *) searchList(cmd->children, (void *) argv[1]);
    if(nextcmd != NULL) {
        for(int i=1;i<argc-1;i++) {
            argv[i] = argv[i+1];
        }
        return executeCommand(nextcmd, argc-1, argv);
    } else {
        return cmd->func(argc, argv);
    }
}