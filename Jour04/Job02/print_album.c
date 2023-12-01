#include <stdio.h>
#include <stdlib.h>
#include "album.h"

void print_album(const t_album *album) {
    my_putstr("\"");
    my_putstr(album->title);
    my_putstr("\" by \"");
    my_putstr(album->artist);
    my_putstr("\" released in ");
    char *year = my_itoa(album->year);
    my_putstr(year);
    free(year);
    my_putstr(".\n");
}