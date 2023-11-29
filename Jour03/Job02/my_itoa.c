#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int my_strlen(const char *str) {
    size_t length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = my_strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char *itoa(int n) {
    int i, sign;
    char *s = malloc(12);
    if (s == NULL) return NULL;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    return s;
}