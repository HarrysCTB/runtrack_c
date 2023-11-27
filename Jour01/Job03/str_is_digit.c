#include <unistd.h>
#include <stddef.h>

int char_is_digit(char c) {
    if (c >= '0' && c <= '9') return 1;
    else return 0;
}

int str_is_digit(char *str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!char_is_digit(str[i])) {
            return 0;
        }
    }
    return 1;
}