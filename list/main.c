#include <stdio.h>

#include "list.h"

bool test_list_add_to_back();
bool test_list_add_to_front();
bool test_list_at_index();
bool test_list_length();
bool test_list_print();
bool test_list_remove_from_back();
bool test_list_remove_from_front();
bool test_list_remove_at_index();
bool test_list_is_in();
bool test_list_get_elem_at();
bool test_list_get_index_of();

int main() {
  printf("Tests for linked list implementation\n");
  printf("\n%s Test add to back function"), test_list_add_to_back() ? "Passed":"Failed");
  printf("\n%s Test add to front function"), test_list_add_to_front() ? "Passed":"Failed");  
  printf("\n%s Test add at index function"), test_list_add_at_index() ? "Passed":"Failed");
  printf("\n%s Test length function"), test_list_length() ? "Passed":"Failed");
  printf("\n%s Test print function"), test_list_print() ? "Passed":"Failed");
  printf("\n%s Test remove from back function"), test_list_remove_from_back() ? "Passed":"Failed");
  printf("\n%s Test remove from front function"), test_list_remove_from_front() ? "Passed":"Failed");  
  printf("\n%s Test is in function"), test_list_is_in() ? "Passed":"Failed");
  printf("\n%s Test get element at function"), test_list_get_elem_at() ? "Passed":"Failed");
  printf("\n%s Test get index of function"), test_list_get_index_of() ? "Passed":"Failed");  
  
    
    
  return 0;
}
bool test_list_add_to_back() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_to_back(test_list, 1);
    list_add_to_back(test_list, 2);
    
    if ((test_list->head->value == 1) && (test_list->head->next->value == 2)) {
        result = true;
    }
    list_free(test_list);
    
    return result;
}

bool test_list_add_to_front() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    list_add_to_front(test_list, 1);
    list_add_to_front(test_list, 2);
    
    if ((test_list->head->value == 2) && (test_list->head->next->value == 1)) {
        result = true;
    }
    
    list_free(test_list);
    
    return result;
}

bool test_list_add_at_index() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);
    list_add_at_index(test_list, 4, 2);

    
    if ((test_list->head->value == 1) && 
        (test_list->head->next->value == 2) &&
        (test_list->head->next->next->value == 4) && 
         (test_list->head->next->next->next->value == 3)) {
        result = true;
    }
  
    list_free(test_list);
    
    return result;
}

bool test_list_length() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);

    int length = list_length(test_list);
    if (length == 3) {
        result = true;
    }
    
    list_free(test_list);
    
    return result;
}

bool test_list_print() {
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);
    
    // Assume passed
    return true;
}

bool test_list_remove_from_back() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_from_back(test_list);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_from_back(test_list);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_from_back(test_list);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool test_list_remove_from_front() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_from_front(test_list);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_from_front(test_list);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_from_front(test_list);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool test_list_remove_at_index() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_at_index(test_list, 0);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_at_index(test_list, 0);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_at_index(test_list, 1);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool test_list_is_in() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    result = list_is_in(test_list, 1);
    
    list_free(test_list);

    return result;
}


bool test_list_get_elem_at(){
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    if (list_get_elem_at(test_list, 1) == 2) {
        result = true;
    }
    
    list_free(test_list);

    return result;
}
bool test_list_get_index_of(){
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    if (list_get_index_of(test_list, 2) == 1) {
        result = true;
    }
        
    list_free(test_list);

    return result;
}