#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "triangle.h"


/**
 * Compute area of triangle
 *
 * 1. compute base by subtracting point a from point b
 * 2.a. c' = projection of c on ab
 * 2.b. compute height by computing z = c - c'
 * 3. triangle area = .5 * (base * height)
 */
float triangle_area(triangle t) {
  float ab_x, ab_y, ab_len, ab_ab;
  float c_ab, c_ab_div_ab_len;
  point proj_c, z;
  float z_len;
  ab_x = t.a.x - t.b.x;
  ab_y = t.a.y - t.b.y;
  
  /* ||ab|| = length of ab = dot product ab*ab */
  ab_ab = ab_x*ab_x + ab_y*ab_y;
  ab_len = sqrt(ab_x*ab_x + ab_y*ab_y);
  /* 2. find projection of c onto ab */
  /* c.ab */
  c_ab = (t.c.x * ab_x) + (t.c.y * ab_y);
  /* proj_c ab = ((c*ab)/(ab*ab))*<ab> */
  c_ab_div_ab_len = c_ab/ab_ab;
  proj_c.x = c_ab_div_ab_len * ab_x;
  proj_c.y = c_ab_div_ab_len * ab_y;
  
  /* z = c - proj_c */
  z.x = t.c.x - proj_c.x;
  z.y = t.c.y - proj_c.y;
  /* ||z|| = z*z = height */
  z_len = sqrt(z.x*z.x + z.y*z.y);
  /* area = 0.5 * base * height */
  return 0.5 * z_len * ab_len;
}

int main() {
  triangle t;
  t.a.x = 0.0; t.a.y = 0.0;
  t.b.x = 1.0; t.b.y = 1.0;
  t.c.x = 0.0; t.c.y = 1.0;
  printf("Area of triangle t is: %4f\n",triangle_area(t));
  return 0;
}
