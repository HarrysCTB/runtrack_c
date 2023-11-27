#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    unsigned char char_s1 = *s1;
    unsigned char char_s2 = *s2;

    int difference = char_s1 - char_s2;

    return difference;
}