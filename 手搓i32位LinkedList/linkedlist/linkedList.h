//
// Created by 26432 on 2026/5/7.
//

#ifndef CLINE_LINKEDLIST_H
#define CLINE_LINKEDLIST_H
#include "typedef.h"

typedef struct Node{
    i32             v;
    struct Node*    next;
}Node;

typedef struct LinkedList{
    struct Node*    head;
    i32             size;
    i32             len;
}LinkedList;

LinkedList* linkedlist_i32_create_new_linkedlist();

Node* linkedlist_i32_create_new_node();

void linkedlist_i32_destroy_arr(i32** arr);

i32 linkedlist_i32_get_size(LinkedList* linkedList);

void linkedlist_i32_add(i32 v, LinkedList *linkedList);

void linked_list_i32_print(LinkedList *linkedList);

i32 *linkedlist_i32_to_array(LinkedList *linkedList);

void linkedlist_i32_destroy(LinkedList** linkedList);


#endif //CLINE_LINKEDLIST_H
