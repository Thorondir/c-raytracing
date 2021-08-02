#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec.h"

typedef struct {
    vec3 p;
    vec3 normal;
    double t;
} hit_record;

#endif
