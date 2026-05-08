#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    LinkedList* list = linkedlist_i32_create_new_linkedlist();
    printf("[LINKEDLIST] list size is : %d\n" , list->size);
    linkedlist_i32_add(23 , list);
    linkedlist_i32_add(34 , list);
    linkedlist_i32_add(103 , list);
    linkedlist_i32_add(12390 , list);
    linkedlist_i32_add(4234 , list);
    linkedlist_i32_add(52 , list);
    linked_list_i32_print(list);
    i32 size = linkedlist_i32_get_size(list);
    printf("list size is : %d\n" , size);
    i32 *arrList = linkedlist_i32_to_array(list);
    for (int i = 0; i < list->len; i++) {
        printf("[POINTER PRINT] arrList current index is %d"
               " value is : %d\n" , i , arrList[i]);
    }
    //free
    linkedlist_i32_destroy_arr(&arrList);
    if (arrList == NULL){
        printf("arrList is NULL!!\n");
    }else{
        printf("arrList not's NULL!!\n");
    }
    linkedlist_i32_destroy(&list);
    if (list == NULL){
        printf("list is NULL!!\n");
    }else{
        printf("list not's NULL!!\n");
    }
}
