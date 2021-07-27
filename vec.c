#include "vec.h"

vec3* vec__create_zero() {
    vec3* new = (vec3*) malloc(sizeof(vec3));
    new->x = 0;
    new->y = 0;
    new->z = 0;
    return new;
}
vec3* vec__create(double x, double y, double z) {
    vec3* new = (vec3*) malloc(sizeof(vec3));
    new->x = x;
    new->y = y;
    new->z = z;
    return new;
}

double vec__x(vec3* v) {
    return v->x;
}
double vec__y(vec3* v) {
    return v->y;
}
double vec__z(vec3* v) {
    return v->z;
}

void vec__neg(vec3* v) {
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
}
void vec__add(vec3* a, vec3* b) {
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}
void vec__sub(vec3* a, vec3* b) {
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
}
void vec__mul_scalar(vec3* v, double s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

double vec__mag(vec3* v) {
    return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}
