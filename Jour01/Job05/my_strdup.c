#include <stdlib.h>
#include <stddef.h>

void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

int my_strlen(const char *str) {
    size_t length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

char *my_strdup(const char *src) {
    size_t len = my_strlen(src);

    char *dest = malloc((len + 1) * sizeof(char));
    if (dest == NULL) return NULL;

    my_strcpy(dest, src);

    return dest;
}