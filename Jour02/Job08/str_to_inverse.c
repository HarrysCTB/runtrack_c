#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        my_putchar(str[i]);
    }
}

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

    char *result = malloc(end_str - str + 2);
    if (result == NULL) return NULL;

    my_strcpy(result, str);
    result[end_str - str + 1] = '\0';

    return result;
}

int my_strcmp(const char *s1, const char *s2) {
    if (!s1 || !s2) return -1;
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    unsigned char char_s1 = *s1;
    unsigned char char_s2 = *s2;

    int difference = char_s1 - char_s2;

    return difference;
}

void sort(char **strs) {
    if (strs == NULL) return;

    int i, j;
    char *temp;

    for (i = 0; strs[i] != NULL; i++);
    for (j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (strs[k] == NULL || strs[k + 1] == NULL) {
                continue;
            }

            if (my_strcmp(strs[k], strs[k + 1]) > 0) {
                temp = strs[k];
                strs[k] = strs[k + 1];
                strs[k + 1] = temp;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        my_putchar("\n");
        return 0;
    }

    char **trimmed_args = malloc((argc - 1) * sizeof(char *));
    for (int i = 1; i < argc; i++) {
        trimmed_args[i - 1] = trim(argv[i]);
    }
    sort(trimmed_args);

    for (int i = 0; i < argc - 1; i++) {
        my_putstr(trimmed_args[i]);
    }

    my_putchar("\n");

    free(trimmed_args);

    return 0;
}
