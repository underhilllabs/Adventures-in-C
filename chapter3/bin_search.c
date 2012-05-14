#include <stdio.h>
#define max 16

int s[max] = {1, 3, 5, 6, 7, 8, 10, 13, 23, 32,33,34,41,42, 45, 46}; 
int p, q, r;

/**
 * bin_search: binary search, 
 * @param low, high, v (value to search for)
 */
int bin_search(int low, int high, int v) {
  printf("called bin_search with low:%d, high:%d, v:%d\n",low,high,v);
  if (low > high) {
    return -1;
  }
  int mid = ((high-low)/2) + low;

  /* If v is in middle, return index. */
  if (v == s[mid]) {
    return mid;
  }

  /* Otherwise, mid doesn't contain v, so ignore on recursive calls. */
  if (v < s[mid]) {
    bin_search(low, mid-1, v);
  } else {
    bin_search(mid+1, high, v);
  }
}

main() {
  
  p = 46;
  q = 6; 
  r = 13;
  printf("\n");
  printf("bin_search for %d, returns idx=> %d\n", p, bin_search(0,max-1, p));
  printf("\n");
  printf("bin_search for %d, returns idx=> %d\n", q, bin_search(0,max-1, q));
  printf("\n");
  printf("bin_search with %d, returns idx=> %d\n", r, bin_search(0,max-1, r));
}
