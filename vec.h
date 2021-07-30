#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
    double z;
} vec3;
typedef vec3 colour;

vec3* vec__create_zero();
vec3* vec__create(double, double, double);
vec3 vec__copy(vec3*);

double vec__x(vec3*);
double vec__y(vec3*);
double vec__z(vec3*);

void vec__neg(vec3*);
void vec__add(vec3*, vec3*);
void vec__sub(vec3*, vec3*);
void vec__mul_scalar(vec3*, double);

double vec__mag(vec3*);

inline vec3 vec__unit(vec3* d) {
    double inv_mag = 1/vec__mag(d);
    vec3 u = {d->x * inv_mag, d->y * inv_mag, d->z * inv_mag};
    return u;
}

inline double vec__dot(vec3* a, vec3* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

#endif
