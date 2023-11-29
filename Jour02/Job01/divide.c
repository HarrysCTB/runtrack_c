#include <stdio.h>

void divide(int *val)
{
    if (val != NULL) {
        *val = *val / 2;
    }
}