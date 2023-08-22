// #include "linked_list.h"
#include "dbl_linked_list.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int x = 1;
    int y = 2;
    int z = 100;

    // Initialize LinkedList
    DblLinkedList ll = new_dbl_linked_list();
    init_dbl_linked_list(&ll, &x, sizeof(int));
    // ll.node_val_size = sizeof(int);
    // ll.len = 0;

    // Insert Nodes
    print_dbl_linked_list(&ll);
    insert_dbl_node(&ll, 1, &x);
    insert_dbl_node(&ll, 1, &y);
    insert_dbl_node(&ll, 1, &y);
    insert_dbl_node(&ll, ll.len / 2, &z);
    // insert_dbl_node_at_head(&ll, &x);

    // Print Linked List Elements
    print_dbl_linked_list(&ll);
    // append_dbl_node(&ll, &x);

    // Print Linked List Elements
    // print_dbl_linked_list(&ll);

    // Free Linked List
    delete_dbl_linked_list(&ll);

    return 0;
}
