#include "ray.h"

void ray__at(vec3* v, ray* r, double t) {
    v->x = r->orig.x + t * r->dir.x;
    v->y = r->orig.y + t * r->dir.y;
    v->z = r->orig.z + t * r->dir.z;
}
