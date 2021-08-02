#include "sphere.h"

bool sphere__hit(ray* r, double t_min, double t_max, hit_record* hr, sphere* s) {
    vec3 o = r->orig;
    vec__sub(&o, s->centre);
    double a = vec__dot(&r->dir, &r->dir);
    double half_b = vec__dot(&r->dir, &o);
    double c = vec__dot(&o, &o) - pow(s->radius, 2);
    double discriminant = pow(half_b, 2) -  a * c;

    if (discriminant < 0) return false;
    double sqrtd = sqrt(discriminant);
    double root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    hr->t = root;
    ray__at(&hr->p, r, root);
    vec3 normal = hr->p;

}
