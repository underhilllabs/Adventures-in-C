typedef struct { float x; float y; } point;
float distance(point a, point b);
float distance_taxicab(point a, point b);
/* place polar coords of x and y into r and theta */
void polar(float x, float y, float *r, float *theta); 
