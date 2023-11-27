#include <unistd.h>

void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}
