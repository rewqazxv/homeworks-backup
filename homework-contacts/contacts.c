#include "contacts.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

List contacts;

void contacts_init() {
    contacts = make_list(sizeof(PersonInfo));
}

int contacts_add(const PersonInfo *pI) {
    list_push_back(contacts, pI);
    return CONTACTS_OK;
}

list_PtrToNode contacts_getnptr(size_t n) {
    list_PtrToNode p = list_begin(contacts);
    size_t i = 0;
    for (; p != list_end(contacts) && i < n; i++, p = p->next);
    if (i == n) return p;
    else return 0;
}

int contacts_delete(size_t n) {
    list_PtrToNode p = contacts_getnptr(n);
    if (p) {
        list_erase(contacts, p);
        return CONTACTS_OK;
    } else return CONTACTS_ERR;
}

int contacts_save(const char *file_name) {
    FILE *f = fopen(file_name, "w");
    if (f) {
        for (list_PtrToNode p = list_begin(contacts); p != list_end(contacts); p = p->next)
            fprintf(f,
                    "%s\n"
                    "%s\n"
                    "%s\n"
                    "%s\n"
                    "%s\n\n",
                    list_getdata_ref(p, PersonInfo).name,
                    list_getdata_ref(p, PersonInfo).street,
                    list_getdata_ref(p, PersonInfo).city,
                    list_getdata_ref(p, PersonInfo).eip,
                    list_getdata_ref(p, PersonInfo).state
                   );
        fclose(f);
        return CONTACTS_OK;
    } else return CONTACTS_ERR;
}

char *scanline(char *s, size_t n, FILE *f) {
    int c;
    size_t cnt = 0;
    while ((c = getc(f)) != EOF && isspace(c));
    if (c == EOF) return 0;
    while (cnt < n - 1 && c != EOF && c != '\n') {
        s[cnt++] = c;
        c = getc(f);
    }
    s[cnt] = 0;
    while (c != EOF && c != '\n') c = getc(f);
    return s;
}

int contacts_load(const char *file_name) {
    list_clear(contacts);
    FILE *f = fopen(file_name, "r");
    if (f) {
        PersonInfo t;
        while (
            scanline(t.name, MAX_CSTR_SIZE, f) &&
            scanline(t.street, MAX_CSTR_SIZE, f) &&
            scanline(t.city, MAX_CSTR_SIZE, f) &&
            scanline(t.eip, MAX_CSTR_SIZE, f) &&
            scanline(t.state, MAX_CSTR_SIZE, f)
        ) contacts_add(&t);
        fclose(f);
        return CONTACTS_OK;
    } else return CONTACTS_ERR;
}

size_t *contacts_search(const char *name) {
    static size_t res[MAX_SEARCH + 1];
    size_t top = 0;

    size_t i = 0;
    list_PtrToNode p = list_begin(contacts);
    for (; top < MAX_SEARCH && p != list_end(contacts); i++, p = p->next)
        if (strcmp(name, list_getdata_ref(p, PersonInfo).name) == 0)
            res[top++] = i;

    res[top] = (size_t) -1;
    return res;
}
