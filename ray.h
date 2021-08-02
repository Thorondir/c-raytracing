#ifndef RAY_H
#define RAY_H

#include "vec.h"

typedef struct {
    vec3 orig;
    vec3 dir;
} ray;

void ray__at(vec3*, ray*, double);

#endif
