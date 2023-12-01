#include "manhattan.h"
#include <stdlib.h>

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

int manhattan(point a, point b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}
