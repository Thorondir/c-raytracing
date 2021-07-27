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

double vec__x(vec3*);
double vec__y(vec3*);
double vec__z(vec3*);

void vec__neg(vec3*);
void vec__add(vec3*, vec3*);
void vec__sub(vec3*, vec3*);
void vec__mul_scalar(vec3*, double);

double vec__mag(vec3*);

#endif
