#include "colour.h"

void write_colour(FILE* ostream, colour* pixel_colour) {
    fprintf(ostream, "%d %d %d\n",
            (int) (pixel_colour->x * 255.999),
            (int) (pixel_colour->y * 255.999),
            (int) (pixel_colour->z * 255.999));
}
