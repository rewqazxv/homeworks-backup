#include "list.h"
#include <stdlib.h>
#include <string.h>

List make_list(size_t element_size) {
    list_PtrToNode head = malloc(sizeof(list_Node) + sizeof(list_Info));
    // head == end
    head->prev = head->next = head;
    list_getdata_ref(head, list_Info).element_size = element_size;
    list_getdata_ref(head, list_Info).size = 0;
    return head;
}

#define list_size_ref(li) \
    list_getdata_ref(li, list_Info).size

list_PtrToNode list_insert(List li, list_PtrToNode pos, const void *ptr_to_val) {
    size_t sz = list_element_size(li);
    list_PtrToNode new_node = malloc(sizeof(list_Node) + sz);

    new_node->next = pos;
    new_node->prev = pos->prev;
    pos->prev->next = new_node;
    pos->prev = new_node;

    memcpy(new_node->data, ptr_to_val, sz);
    list_size_ref(li) += 1;
    return new_node;
}

list_PtrToNode list_erase(List li, list_PtrToNode pos) {
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    list_PtrToNode after = pos->next;
    free(pos);
    list_size_ref(li) -= 1;
    return after;
}

// delete all elements, leave an empty list
void list_clear(List li) {
    while (list_begin(li) != list_end(li))
        list_erase(li, list_begin(li));
}

// release all resources (delete list)
void list_release(List *pli) {
    list_clear(*pli);
    free(*pli);
    *pli = NULL;
}
