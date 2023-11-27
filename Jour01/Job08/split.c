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

    const char *end_str = str + my_strlen(str) - 1;
    while (end_str > str && *end_str == ' ') end_str--;

    if (end_str < str) {
        end_str = str - 1;
    }

    char *result = malloc(end_str - str + 2);
    if (result == NULL) return NULL;

    my_strcpy(result, str);
    result[end_str - str + 1] = '\0';

    return result;
}

char **split(const char *str) {
    char *trimmed_str = trim(str);
    if (!trimmed_str) return NULL;

    int count = 0;
    const char *ptr = trimmed_str;
    while (*ptr) {
        if (*ptr != ' ') {
            count++;
            while (*ptr && *ptr != ' ') ptr++;
        } else {
            ptr++;
        }
    }

    char **result = malloc((count + 1) * sizeof(char *));
    if (!result) {
        free(trimmed_str);
        return NULL;
    }

    int word_idx = 0;
    ptr = trimmed_str;
    while (*ptr) {
        if (*ptr != ' ') {
            const char *start = ptr;
            while (*ptr && *ptr != ' ') ptr++;

            int word_length = ptr - start;
            result[word_idx] = (char *)malloc(word_length + 1);
            if (!result[word_idx]) {
                for (int j = 0; j < word_idx; j++) {
                    free(result[j]);
                }
                free(result);
                free(trimmed_str);
                return NULL;
            }
            strncpy(result[word_idx], start, word_length);
            result[word_idx][word_length] = '\0';
            word_idx++;
        } else {
            ptr++;
        }
    }

    result[word_idx] = NULL;
    free(trimmed_str);
    return result;
}

