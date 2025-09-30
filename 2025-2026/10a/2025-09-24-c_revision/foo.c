#include "foo.h"
#include <math.h>
float dist2 (Point2* p1, Point2* p2) {
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}