#ifndef RAY_H
#define RAY_H

#include "vec.h"

typedef struct {
    vec3 orig;
    vec3 dir;
} ray;

vec3* ray__at(ray*, double);

#endif
