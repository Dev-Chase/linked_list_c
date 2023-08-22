#include "linked_list.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int x = 1;
    int y = 2;
    int z = 100;

    // Initialize LinkedList
    LinkedList ll = new_linked_list();
    init_linked_list(&ll, &x, sizeof(int));

    // Insert Nodes
    insert_node(&ll, 1, &y);
    insert_node(&ll, 1, &z);
    insert_node(&ll, 1, &z);
    insert_node(&ll, 1, &y);

    // Print Linked List Elements
    print_linked_list(&ll);

    // Free Linked List
    delete_linked_list(&ll);

    return 0;
}
