#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList new_linked_list(void) {
    return (LinkedList){
        .len = 0,
        .head = NULL,
        .tail = NULL,
        .node_val_size = 0,
    };
}

void init_linked_list(LinkedList *list, void *val, size_t size) {
    // Allocate Memory for Head
    list->head = malloc(sizeof(Node));

    // Malloc Error Checks
    if (list->head == NULL) {
        perror("error creating list head");
        exit(EXIT_FAILURE);
    }

    // Initializing List Head
    list->head->next = NULL;
    list->head->val = val;

    // Set Head = Tail = Cur because len == 1
    list->tail = list->head;

    // Initialize Node Length and Size
    list->node_val_size = size;
    list->len = 1;
}

void delete_linked_list(LinkedList *list) {
    Node *cur = list->head;
    Node *next = cur->next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    list->node_val_size = 0;
}

void print_linked_list(LinkedList *list) {
    Node *cur = list->head;

    int i = 0;
    while (cur != NULL) {
        printf("[#%d=%d] -> ", i, *(int *)cur->val);
        cur = cur->next;
        i++;
    }
    printf("NULL\n");
}

void insert_node(LinkedList *list, size_t ind, void *val) {
    // Index Bounds Check
    if (ind > list->len + 1) {
        fprintf(stderr, "can't insert in index %zu as it is out of bounds\n",
                ind);
        return;
    }

    // If the Index is at the Beginning
    if (ind == 0) {
        insert_node_at_head(list, val);
        return;
    }
    // If the Index is at the Very End
    if (ind == list->len) {
        append_node(list, val);
        return;
    }

    // Any Other Index
    Node *cur = list->head;
    for (size_t i = 0; i < ind - 1; i++) {
        cur = cur->next;
    }
    Node *old_next = cur->next;
    cur->next = malloc(sizeof(Node));
    if (cur->next == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }
    cur->next->next = old_next;
    cur->next->val = val;

    list->len++;
}

void append_node(LinkedList *list, void *val) {
    // Allocating Memory for New Node
    list->tail->next = malloc(sizeof(Node));

    // Malloc Error Checks
    if (list->tail->next == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }

    // New Tail Becomes Actual Tail
    list->tail = list->tail->next;

    // Set Defaults for New Tail
    list->tail->next = NULL;
    list->tail->val = val;

    // Increment List Len
    list->len++;
}

void insert_node_at_head(LinkedList *list, void *val) {
    // Allocating Memory for New Node
    Node *old_head = list->head;
    list->head = malloc(sizeof(Node));

    // Malloc Error Checks
    if (list->head == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }

    // Setting Default Values for New Head
    list->head->next = old_head;
    list->head->val = val;

    // Increment List Len
    list->len++;
}

Node *get_node(LinkedList *list, size_t ind) {
    // Index Bounds Checking
    if (ind >= list->len) {
        fprintf(stderr, "error: index out of bounds\t NULL returned\n");
        return NULL;
    }

    // Initialize Current Node Ptr
    Node *cur = list->head;

    // Move Current Ptr Ind Times
    for (int i = 0; i < ind; i++) {
        cur = cur->next;
    }

    // Return Current Ptr
    return cur;
}

void *get_node_val(LinkedList *list, size_t ind) {
    // Index Bounds Checking
    if (ind >= list->len) {
        fprintf(stderr, "error: index out of bounds\t NULL returned\n");
        return NULL;
    }

    // Initialize Current Node Ptr
    Node *cur = list->head;

    // Move Current Ptr Ind Times
    for (int i = 0; i < ind; i++) {
        cur = cur->next;
    }

    // Return Current Val
    return cur->val;
}
