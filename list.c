#include "list.h"

void initList(list_t *list) {
    
    list->head = NULL;
    list->match = NULL;
}

list_t *addNodeList(list_t *list, void *data) {
    listNode_t *node = calloc(1, sizeof(listNode_t));
    node->data = data;

    if (list->head == NULL) {
        list->head = node;
        node->next = NULL;
    } else {
        node->next = list->head;
        list->head = node;
    }
    return list;
}

void *searchList(list_t *list, void *key) {
    if (!list || !list->head) {
        return NULL;
    }

    listNode_t *node = list->head;
    while(node) {
        if(list->match(node->data, key) == 0) {
            return (void *) node->data;
        }
        node = node->next;
    }
    return NULL;
}
