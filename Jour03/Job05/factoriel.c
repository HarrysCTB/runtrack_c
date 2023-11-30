#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void my_putnbr(int nb) {
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }

    if (nb >= 10) {
        my_putnbr(nb / 10);
    }

    my_putchar((nb % 10) + '0');
}

int my_atoi(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }
    result *= sign;

    return result;
}

int factor(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factor(n - 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        my_putstr("Usage: ");
        my_putstr(argv[0]);
        my_putstr(" number\n");
        return 1;
    }

    int number = atoi(argv[1]);
    int result = factor(number);
    my_putstr("Le factoriel de ");
    my_putnbr(number);
    my_putstr(" est ");
    my_putnbr(result);
    my_putstr("\n");
    return 0;
}