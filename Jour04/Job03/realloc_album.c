#include <stdlib.h>
#include <string.h>
#include "album.h"

t_album *realloc_album(t_album *albums, int size, int newsize) {
    t_album *new_albums = (t_album *)malloc(newsize * sizeof(t_album));
    for (int i = 0; i < size; i++) {
        new_albums[i] = albums[i];
    }

    free(albums);
    return new_albums;
}
