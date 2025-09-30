#ifndef _POINT_H_
#define _POINT_H_

typedef struct Point2 {
    float x;
    float y;
} Point2;

float dist2(Point2* a, Point2* b);

#endif