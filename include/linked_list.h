#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdint.h>

typedef struct Node {
    void *val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    size_t len;
    size_t node_val_size;
} LinkedList;

LinkedList new_linked_list(void);
void init_linked_list(LinkedList *list, void *val, size_t size);
void delete_linked_list(LinkedList *list);
void print_linked_list(LinkedList *list);
void insert_node(LinkedList *list, size_t ind, void *val);
void insert_node_at_head(LinkedList *list, void *val);
void append_node(LinkedList *list, void *val);
void del_node_i(LinkedList *list, uint_fast32_t ind);
Node *get_node(LinkedList *list, size_t ind);
void *get_node_val(LinkedList *list, size_t ind);

#ifdef __cplusplus
}
#endif

#endif
