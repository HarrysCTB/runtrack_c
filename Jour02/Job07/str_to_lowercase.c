#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}


int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            my_putchar(to_lower(argv[i][j]));
        }
        my_putchar('\n');
    }
    return 0;
}
