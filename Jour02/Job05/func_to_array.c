#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

void func_to_array(char **strs, void (*functionToApply)(char *)) {
    if (strs == NULL || functionToApply == NULL) return;

    for (int i = 0; strs[i] != NULL; i++) {
        functionToApply(strs[i]);
    }
}

