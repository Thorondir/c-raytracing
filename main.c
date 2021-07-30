#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "colour.h"
#include "ray.h"
#include "vec.h"

// inline unit vector function
double vec__dot(vec3*, vec3*);
vec3 vec__unit(vec3*);

double hit_sphere(vec3* centre, double radius, ray* r) {
    // det = b^2 - 4ac
    vec3 temp = vec__copy(&r->orig);
    vec__sub(&temp, centre); // A-C
    double b = 2*vec__dot(&r->dir, &temp);
    double ac = vec__dot(&r->dir, &r->dir) * vec__dot(&temp, &temp) - pow(radius, 2);
    double determinant = sqrt(pow(b, 2) - 4 * ac);

    return determinant > 0;
}

colour ray_colour(ray* r) {
    vec3 centre = {0,0,-1};
    if (hit_sphere(&centre, 0.5, r)) {
        colour c = {1,0,0};
        return c;
    }
    vec3 unit_direction = vec__unit(&r->dir);
    double t = 0.5*(unit_direction.y + 1);
    colour c = {1-t * 1 + 0.5*t, 1-t * 1 + 0.7*t, 1-t * 1 + t};
    return c;
}

int main() {
    double aspect_ratio = 16.0/9.0;
    const int image_width = 400;
    const int image_height = (int) image_width / aspect_ratio;

    // camera
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    vec3 origin = {0, 0, 0};
    vec3 horizontal = {viewport_width, 0, 0};
    vec3 vertical = {0, viewport_height, 0};
    vec3 lower_left_corner = origin;
    vec__sub(&lower_left_corner, &horizontal);
    vec__sub(&lower_left_corner, &vertical);
    vec__mul_scalar(&lower_left_corner, 0.5);
    lower_left_corner.z -= focal_length;

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = image_height-1; j>= 0; j--) {
        fprintf(stderr, "\rScanlines remaining: %d", j);
        for (int i = 0; i < image_width; i++) {
            double u = (double) i / (image_width - 1);
            double v = (double) j / (image_height - 1);

            vec3 direction = {lower_left_corner.x + u * horizontal.x - origin.x, lower_left_corner.y + v * vertical.y - origin.y, lower_left_corner.z - origin.z};
            ray r = {origin, direction};

            colour c = ray_colour(&r);

            write_colour(stdout, &c);
        }
    }
    fprintf(stderr, "\nDone.\n");
}
