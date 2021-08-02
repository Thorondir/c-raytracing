#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>

#include "hittable.h"
#include "ray.h"

typedef struct {
    vec3 centre;
    double radius;
} sphere;

bool sphere__hit(ray*, double, double, hit_record*, sphere*);

#endif
