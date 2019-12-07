// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>

#include "list.h"

list_t *list_alloc() {
    
    printf("\nAllocating memory\n");
    //dynamically allocated array
    list_t *l = (list_t*) malloc(*sizeof(int)); 
    l.head = NULL;
    return l; 
}

//freeing each element int the list
void list_free(list_t *l){
    
    node_t *current = l-> head;
    while (current != NULL){
        
        free(list_t);
        current = current ->next;
        
    }
    
    printf("\n list empty, can't remove!");
   
}

//prining each element in the list 
void list_print(list_t *l) {
    node_t *current = l-> head;
    while (current != NULL){
        printf("d%", l ->list_t);
        current = current->next;
    }
    
}


int list_length(list_t *l) { 
    node_t *current = l-> head;
    int count = 0;
    while( current != NULL){
        count ++;
        current = current -> next;
} 
    return count;
}

void list_add_to_back(list_t *l, elem value) {
    node_t *current = l-> head;
    node_t *new_node =(node_t*) malloc(sizeof(int));
    new_node->value=value;
    value->next = NULL;
    if (current == NULL){
        current = new_node;  
    }
    while(current != NULL){
        current = current ->next;  
    }
    current -> next = new_node;
    
}
void list_add_to_front(list_t *l, elem value) {
    node_t *new_node = (node_t*)malloc(sizeof(int));
    new_node -> value = value;
    new_node->next= head;
    l ->head = new_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t *current = l-> head;
    node_t *new_node = (node_t*)malloc(sizeof(int));
    //node_t *prev_node = (node_t*)malloc(sizeof(int));
    int count = 0;
    new_node-> value = value;
    new_node->next= NULL;
    if(head!= NULL){
        printf("Adding head because list empty/n ");
        list_add_to_front();
    }
    
    
    
    
}

elem list_remove_from_back(list_t *l) {
    int value;
    node_t *current = l-> head;
    
    if (current == NULL){
        printf("\nNo elements to rmove.\n");
        return -1;
    }
    else{
        if(list_length(l)< 2){
            l->head=NULL;
            free(current);
        }
        else{
            while(current->next->next != NULL) current = current->next;
            node_t *temp= current->next;
            current->next =NULL;
            free(temp);
        }
    }
 }
elem list_remove_from_front(list_t *l) { 
    node_t *current = l->head;
    if(current == NULL){
        printf("\nNo elements to remove.");
        return -1;
    }
    
    int value = current ->value;
    l->head = (list_length < 2) ? NULL : current -> next;
    free(current);
    return value;
}
elem list_remove_at_index(list_t *l, int index) { 
    node_t *current = l->head;
    node_t *temp;
    int value, count=index;
    
    if((index > list_length(l)+1 || (index <1))){
        printf("\nInvalid index.");
        return -1
    }
    
    else{
        while(count >1){
            current = current -> next;
            count --;
        }
        
        temp = current -> next;
        current -> next = NULL;
        value = temp ->value;
        free(temp);
        printf("\nNode removed from index %d", index);
    }
    return value;
}

bool list_is_in(list_t *l, elem value) { 
    node_t *current = l-> head;
    
    while (current != NULL){
        if (current ->value == value) return true;
        current = current -> next;
    }
    return false;
}
elem list_get_elem_at(list_t *l, int index) { 
    node_t *current = l->head;
    
    if ((index > list_length(l)-1 || index < 0 )){
        print("\nInvalid index.");
        return -1;
    }
    while (current ->next != NULL && index >= 0 ){
        current = current -> next;
        index--;
    }
    return current ->value; 
}

int list_get_index_of(list_t *l, elem value) { 
    node_t *current = l->head;
    int index = 0;
    
    while(current != NULL){
        if(current ->value==value) return index;
        current = current ->next;
        index++;
    }
    return -1;

}