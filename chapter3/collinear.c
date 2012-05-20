#include <stdio.h>
#include "collinear.h"

/** 
 * Check if 3 points are on the same line
 */
int is_collinear(point a, point b, point c) {
  float slope, yint;
  
  /* find slope of line */
  slope = (a.y - b.y)/(a.x - b.x);
  /* find y-intercept */
  /* b = (a.y - 0) - m*(a.x - 0) */
  yint = a.y - slope * a.x;
  /* Now test if point c is on the line */
  /* I feel there would be round off error */
  return c.y == (slope * c.x + yint);
} 


int main() {
  point a, b, c;
  a.y = 0.0; a.x = 0.0;
  b.y = 1.0; b.x = 1.0;
  c.y = 0.5000; c.x = 0.5;

  printf("Is c collinear? %d\n",is_collinear(a,b,c));
  return 0;
}
