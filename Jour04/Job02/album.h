#ifndef ALBUM_H
#define ALBUM_H

typedef struct album {
    char *artist;
    char *title;
    int year;
} t_album;

void print_album(const t_album *album);
void my_putstr(char *str);
char *my_itoa(int n);

#endif
