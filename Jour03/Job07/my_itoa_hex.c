#include <stdio.h>
#include <stdlib.h>

char* itoa_hex(int n) {
    int size = 1;
    int temp = n;
    while (temp / 16 != 0) {
        size++;
        temp /= 16;
    }

    char* str = (char*)malloc((size + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    for (int i = size - 1; i >= 0; i--) {
        int remainder = n % 16;
        if (remainder < 10) {
            str[i] = remainder + '0';
        } else {
            str[i] = remainder - 10 + 'A';
        }
        n /= 16;
    }

    str[size] = '\0';

    return str;
}
