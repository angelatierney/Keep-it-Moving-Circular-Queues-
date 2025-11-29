#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t list_create() {
    return NULL;
}

int list_push(list_t* this_list, int add_value) {
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return 0; // Memory allocation failed
    }
    new_node->value = add_value;
    new_node->next = *this_list; 
    *this_list = new_node;       // Update head to new node
    return 1;
}

void list_print(list_t* this_list) {
    node_t* curr = *this_list;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int list_pop(list_t* this_list) {
    if (*this_list == NULL) {
        return -1; // Empty list
    }
    node_t* old_head = *this_list;
    int value = old_head->value;
    *this_list = old_head->next; 
    free(old_head);              
    return value;
}

int list_remove(list_t* this_list, int remove_value) {
    if (*this_list == NULL) {
        return 0; // Empty list
    }
    // Special case: head has the value
    if ((*this_list)->value == remove_value) {
        node_t* old_head = *this_list;
        *this_list = old_head->next;
        free(old_head);
        return 1;
    }
    
    node_t* curr = *this_list;
    while (curr->next != NULL) {
        if (curr->next->value == remove_value) {
            node_t* to_remove = curr->next;
            curr->next = to_remove->next; // Skip the node
            free(to_remove);
            return 1;
        }
        curr = curr->next;
    }
    return 0; 
}

void list_free(list_t* this_list) {
    node_t* curr = *this_list;
    while (curr != NULL) {
        node_t* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *this_list = NULL; // Ensure the list is marked empty
}


