#include <unistd.h>
#include <stddef.h>

int my_strlen(const char *str) {
    size_t length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}