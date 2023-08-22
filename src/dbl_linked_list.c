#include "dbl_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: implement prev
DblLinkedList new_dbl_linked_list(void) {
    return (DblLinkedList){
        .len = 0,
        .head = NULL,
        .tail = NULL,
        .node_val_size = 0,
    };
}

void init_dbl_linked_list(DblLinkedList *list, void *val, size_t size) {
    // Allocate Memory for Head
    list->head = malloc(sizeof(DblNode));

    // Malloc Error Checks
    if (list->head == NULL) {
        perror("error creating list head");
        exit(EXIT_FAILURE);
    }

    // Initializing List Head
    list->head->next = NULL;
    list->head->prev = NULL;
    list->head->val = val;

    // Set Head = Tail = Cur because len == 1
    list->tail = list->head;

    // Initialize Node Length and Size
    list->node_val_size = size;
    list->len = 1;
}

void delete_dbl_linked_list(DblLinkedList *list) {
    DblNode *cur = list->head;
    DblNode *next = cur->next;

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

void print_dbl_linked_list(DblLinkedList *list) {
    DblNode *cur = list->head;

    int i = 0;
    printf("NULL");
    while (cur != NULL) {
        printf(" <- [#%d=%d] -> ", i, *(int *)cur->val);
        cur = cur->next;
        i++;
    }
    printf("NULL\n");
}

void insert_dbl_node(DblLinkedList *list, size_t ind, void *val) {
    // Index Bounds Check
    if (ind > list->len + 1) {
        fprintf(stderr, "can't insert in index %zu as it is out of bounds\n",
                ind);
        return;
    }

    // If the Index is at the Beginning
    if (ind == 0) {
        insert_dbl_node_at_head(list, val);
        return;
    }
    // If the Index is at the Very End
    if (ind == list->len) {
        append_dbl_node(list, val);
        return;
    }

    // Any Other Index:
    // Initialize Cur Ptr
    DblNode *node_ptr = list->head;

    // Set Cur Ptr to Requested Index
    for (size_t i = 0; i < ind - 1; i++) {
        node_ptr = node_ptr->next;
    }

    // Allocate Memory for New Node
    node_ptr->next->prev = malloc(sizeof(DblNode));

    // Malloc Error Checks
    if (node_ptr->next->prev == NULL) {
        perror("error");
        exit(EXIT_SUCCESS);
    }

    // Set New Node's Next Ptr
    node_ptr->next->prev->next = node_ptr->next;

    // Insert New Node as Previous Node's Next Ptr
    node_ptr->next = node_ptr->next->prev;

    // Set New Node's Previous Pointer
    node_ptr->next->prev = node_ptr;

    // Assign New Node's Value
    node_ptr->next->val = val;

    // Increment List Length
    list->len++;
}

void append_dbl_node(DblLinkedList *list, void *val) {
    list->tail->next = malloc(sizeof(DblNode));

    if (list->tail->next == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }

    // Make New Tail's Prev Ptr point to Old Tail
    list->tail->next->prev = list->tail;

    // New Tail Becomes Actual Tail
    list->tail = list->tail->next;

    // Set Defaults for New Tail
    list->tail->next = NULL;
    list->tail->val = val;

    // Increment List Len
    list->len++;
}

void insert_dbl_node_at_head(DblLinkedList *list, void *val) {
    list->head->prev = malloc(sizeof(DblNode));

    // Malloc Error Check
    if (list->head->prev == NULL) {
        perror("error");
        exit(EXIT_FAILURE);
    }

    // Point New Head to Old Head
    list->head->prev->next = list->head;

    // New Head becomes actual Head
    list->head = list->head->prev;

    // Set Defaults for New Head
    list->head->prev = NULL;
    list->head->val = val;

    // Increment List Len
    list->len++;
}

DblNode *get_dbl_node(DblLinkedList *list, size_t ind) {
    // Index Bounds Checking
    if (ind >= list->len) {
        fprintf(stderr, "error: index out of bounds\t NULL returned\n");
        return NULL;
    }

    // Initialize Current Node Ptr
    DblNode *cur = ind > list->len / 2 ? list->tail : list->head;

    // Move Current Ptr Ind Times According to Position in List:
    if (ind > list->len / 2) {
        // Loop Backwards
        for (int i = 0; i < list->len - ind - 1; i++) {
            cur = cur->prev;
        }
    } else {
        // Loop Forwards
        for (int i = 0; i < ind; i++) {
            cur = cur->next;
        }
    }

    // Return Current Ptr
    return cur;
}

void *get_dbl_node_val(DblLinkedList *list, size_t ind) {
    // Index Bounds Checking
    if (ind >= list->len) {
        fprintf(stderr, "error: index out of bounds\t NULL returned\n");
        return NULL;
    }

    // Initialize Current Node Ptr
    DblNode *cur = ind > list->len / 2 ? list->tail : list->head;

    // Move Current Ptr Ind Times According to Position in List:
    if (ind > list->len / 2) {
        // Loop Backwards
        for (int i = 0; i < list->len - ind - 1; i++) {
            cur = cur->prev;
        }
    } else {
        // Loop Forwards
        for (int i = 0; i < ind; i++) {
            cur = cur->next;
        }
    }

    // Return Current Val
    return cur->val;
}
