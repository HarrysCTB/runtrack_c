#include <stdlib.h>
#include "album_list.h"

t_album_list *create_album(char *title, char *artist, int year) {
    t_album_list *album = (t_album_list *)malloc(sizeof(t_album_list));

    album->title = title;
    album->artist = artist;
    album->year = year;
    album->next = NULL;

    return album;
}
