#include <stdio.h>
#include <stdlib.h>
#include "album_list.h"

void album_del_one(t_album_list **list, t_album_list *elem) {
    if (*list == NULL || elem == NULL) {
        return;
    }

    if (*list == elem) {
        *list = elem->next;
        free(elem);
        return;
    }

    t_album_list *prev = *list;
    while (prev->next != NULL && prev->next != elem) {
        prev = prev->next;
    }

    if (prev->next == elem) {
        prev->next = elem->next;
        free(elem);
    }
}
