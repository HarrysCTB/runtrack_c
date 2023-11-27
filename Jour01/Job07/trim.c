#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int my_strlen(const char *str) {
    size_t length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

char *trim(const char *str) {
    while (*str == ' ') str++;

    char *end_str = str + my_strlen(str) - 1;
    while (end_str > str && *end_str == ' ') end_str--;

    char *result = malloc(end_str - str + 2);
    if (result == NULL) return NULL;

    my_strcpy(result, str);
    result[end_str - str + 1] = '\0';

    return result;
}
