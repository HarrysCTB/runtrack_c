
#include <stdlib.h>

void delete_str_array(char ***str_array, int size) {
    for (int i = 0; i < size; i++) {
        free((*str_array)[i]);
    }

    free(*str_array);

    *str_array = NULL;
}