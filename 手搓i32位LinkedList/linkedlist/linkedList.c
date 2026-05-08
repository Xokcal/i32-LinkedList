//
// Created by 26432 on 2026/5/7.
//
#include "typedef.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *linkedlist_i32_create_new_linkedlist() {
    LinkedList *linkedList = (LinkedList *) malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->size = 0;
    return linkedList;
}

Node *linkedlist_i32_create_new_node() {
    Node *node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->v = 0;
    return node;
}

i32 linkedlist_i32_get_size(LinkedList *linkedList) {
    return linkedList->size;
}

void linkedlist_i32_add(i32 v, LinkedList *linkedList) {
    Node *h = linkedList->head;
    Node *newNode = linkedlist_i32_create_new_node();
    newNode->v = v;
    newNode->next = NULL;
    if (linkedList->size == 0) {
        linkedList->head = newNode;
        linkedList->size++;
        return;
    }
    while (h->next != NULL) {
        h = h->next;
    }
    h->next = newNode;
    linkedList->size++;
    return;
}

void linked_list_i32_print(LinkedList *linkedList) {
    Node *h = linkedList->head;
    if (linkedList->size == 0) {
        printf("NULL");
    }
    i32 index = 1;
    printf("[");
    while (h != NULL) {
        if (index == 1) {
            printf("%d", h->v);
            h = h->next;
            index++;
        }else {
            printf("-> %d ", h->v);
            h = h->next;
            index++;
        }
    }
    printf("]\n");
}

i32* linkedlist_i32_to_array(LinkedList *linkedList) {
    if (linkedList->size == 0)return NULL;
    i32 *arr = (i32 *) malloc(linkedList->size * sizeof(i32));
    Node *h = linkedList->head;
    i32 arrIndex = 0;
    while (h != NULL){
        arr[arrIndex] = h->v;
        arrIndex++;
        h = h->next;
    }
    linkedList->len = arrIndex;
    return arr;
}

void linkedlist_i32_reverse(LinkedList* linkedlist){
    if (linkedlist->size == 0)return;
    Node* up = NULL;
    Node* curr = linkedlist->head;
    while (curr != NULL){
        Node* next = curr->next;
        curr->next = up;
        up = curr;
        curr = next;
    }
    linkedlist->head = up;
}

void linkedlist_i32_destroy_arr(i32** arr){
    if (arr == NULL)return;
    free(*arr);
    *arr = NULL;
}

i32 linkedlist_i32_remove_by_v(LinkedList* linkedList , i32 t_v){
    if (linkedList->size == 0){return 0;}
    i32 remove_v = 0;
    Node* h = linkedList->head;
    i32 index = 1;
    Node* up = h;
    while (h != NULL){
        if (h->v == t_v && index == 1){
            linkedList->head = h->next;
            remove_v = h->v;
            free(h);
            linkedList->size--;
            return remove_v;
        }
        if (h->v == t_v && index > 1){
            printf("v=t_v\n");
            remove_v = h->v;
            up->next = h->next;
            free(h);
            linkedList->size--;
            return remove_v;
        }
        if (index > 1){
            up = h;
        }
        h = h->next;
        index++;
    }
    return 0;
}

i32* linkedlist_i32_sort(LinkedList* linkedList){
    i32* arr = linkedlist_i32_to_array(linkedList);
    quckly_sort(arr , 0 , linkedList->size - 1);
    return arr;
}

void quckly_sort(i32* p , i32 left , i32 right){
    if (left >= right)return;
    i32 mid = p[(left + ((right - left) / 2))];
    i32 l = left;
    i32 r = right;
    while (left <= right){
        while (left <= right && p[left] < mid)left++;
        while (left <= right && p[right] > mid)right--;
        if (left <= right){
            i32 t = p[left];
            p[left] = p[right];
            p[right] = t;
            left++;
            right--;
        }
    }
    quckly_sort(p , l , right);
    quckly_sort(p , left , r);
}

void linkedlist_i32_destroy(LinkedList **linkedList) {
    if (linkedList == NULL)return;
    Node *h = (*linkedList)->head;
    while (h != NULL) {
        Node *t = NULL;
        t = h;
        h = h->next;
        free(t);
    }
    free(*linkedList);
    *linkedList = NULL;
}
