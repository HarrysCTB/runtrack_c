#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

void sort(char **strs)
{
    int i, j;
    char *temp;

    for (i = 0; strs[i] != NULL; i++);

    for (j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (my_strcmp(strs[k], strs[k + 1]) > 0) {
                temp = strs[k];
                strs[k] = strs[k + 1];
                strs[k + 1] = temp;
            }
        }
    }
}