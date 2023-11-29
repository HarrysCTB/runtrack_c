#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

int my_strlen(const char *str) {
    size_t length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

char **array_clone(char **strs, int n) {
    char **clone = malloc((n + 1) * sizeof(char *));
    if (clone == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        clone[i] = malloc(my_strlen(strs[i]) + 1);
        if (clone[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(clone[j]);
            }
            free(clone);
            return NULL;
        }
        my_strcpy(clone[i], strs[i]);
    }

    clone[n] = NULL;

    return clone;
}
