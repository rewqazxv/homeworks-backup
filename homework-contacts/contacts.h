#ifndef CONTACTS_H
#define CONTACTS_H

#include "list.h"

#define CONTACTS_OK     0
#define CONTACTS_ERR    1

#define MAX_CSTR_SIZE 50
typedef char cstr[MAX_CSTR_SIZE];
typedef struct {
    cstr name, street, city, eip, state;
} PersonInfo;

extern List contacts;
void contacts_init(); // must initialize first

int contacts_add(const PersonInfo *pI);
int contacts_delete(size_t n);
int contacts_save(const char *file_name);
int contacts_load(const char *file_name);
list_PtrToNode contacts_getnptr(size_t n);

#define MAX_SEARCH 10
// return an array of search result, end with value (size_t)-1
size_t *contacts_search(const char *name);

#endif // CONTACTS_H
