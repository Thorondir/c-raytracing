#include "ray.h"

vec3* ray__at(ray* r, double t) {
    vec3* new = vec__create(r->orig.x + t * r->dir.x, r->orig.y + t * r->dir.y, r->orig.z + t * r->dir.z);
    return new;
}
