typedef struct {
  float x; 
  float y;
} point;

typedef struct {
  point a; 
  point b; 
  point c;
} triangle;

float triangle_area (triangle t);

