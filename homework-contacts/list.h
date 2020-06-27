#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct _list_node   list_Node;
typedef list_Node           *list_PtrToNode;
typedef list_PtrToNode      List;

struct _list_node {
    list_PtrToNode prev, next;
    char data[0];
};

typedef struct {
    size_t element_size;
    size_t size;
} list_Info;

#define list_getdata_ref(ptr_to_node, ElementType) \
    (*(ElementType *) ptr_to_node->data)

List make_list(size_t element_size);

static inline list_PtrToNode list_begin(List li) {
    return li->next;
}

static inline list_PtrToNode list_end(List li) {
    return li;
}

static inline size_t list_size(List li) {
    return list_getdata_ref(li, list_Info).size;
}

static inline size_t list_element_size(List li) {
    return list_getdata_ref(li, list_Info).element_size;
}

// **copy** value to the pos position
// return pointer to the inserted element
list_PtrToNode list_insert(List li, list_PtrToNode pos, const void *ptr_to_val);

// return pointer to the element after the deleted one
list_PtrToNode list_erase(List li, list_PtrToNode pos);

static inline void list_push_front(List li, const void *ptr_to_val) {
    list_insert(li, list_begin(li), ptr_to_val);
}

static inline void list_pop_front(List li) {
    list_erase(li, list_begin(li));
}

static inline void list_push_back(List li, const void *ptr_to_val) {
    list_insert(li, list_end(li), ptr_to_val);
}

static inline void list_pop_back(List li) {
    list_erase(li, list_end(li)->prev);
}

// delete all elements, leave an empty list
void list_clear(List li);

// release all resources (delete list)
void list_release(List *pli);

#endif // LIST_H
