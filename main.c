#include <stdio.h>

#include "colour.h"
#include "vec.h"

int main() {
    const int image_width = 256;
    const int image_height = 256;

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = image_height-1; j>= 0; j--) {
        fprintf(stderr, "\rScanlines remaining: %d", j);
        for (int i = 0; i < image_width; i++) {
            colour* c = vec__create((double) i / (image_width - 1), (double) j / (image_height - 1), 0.25);

            write_colour(stdout, c);
        }
    }
    fprintf(stderr, "\nDone.\n");
}
