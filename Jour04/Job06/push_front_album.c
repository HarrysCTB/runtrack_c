#include <stdlib.h>
#include "album_list.h"

void push_front_album(t_album_list **list, t_album_list *album) {
    if (*list == NULL) {
        *list = album;
        album->next = NULL;
    } else {
        album->next = *list;
        *list = album;
    }
}
