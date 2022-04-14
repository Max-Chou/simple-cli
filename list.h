#ifndef LIST_H_
#define LIST_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct listNode_ {
    struct listNode_ *next;
    void *data;
} listNode_t;

typedef struct list_ {
    listNode_t *head;
    int (*match)(void *ptr, void *key);
} list_t;

#define setMatchList(l, m) ((l)->match = (m))


void initList(list_t *list);
list_t *addNodeList(list_t *list, void *data);
void *searchList(list_t *list, void *key);

#endif