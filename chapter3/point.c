#include <math.h>
#include "Point.h"

float distance(point a, point b) {
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

/**
 * Taxicab metric
 * return sum of floating point abs value of differences of x and y points 
 */
float distance_taxicab(point a, point b) {
  return fabs(a.x - b.x) + fabs(a.y - b.y);
}

/**
 * Translate from euclidean to Polar Coordinates
 */
polar(float x, float y, float *r, float *theta) {
  *r = sqrt(x*x + y*y);
  *theta = atan2(y, x);
}
  
