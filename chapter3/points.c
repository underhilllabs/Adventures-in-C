#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Point.h"

float distance(point a, point b) {
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  point a = 

