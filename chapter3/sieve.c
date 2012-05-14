#include <stdio.h>
#define N 1000000

/* 
 * Sieve of Erasthones 
 * 
 * Compute Prime numbers from 1 to N
 * 1. set each element in array to 1
 * 2. loop from 2 to N/2
 *   3. set each multiple of i to 0.
 * 4. print out remaining 1's which are prime numbers.
 */
int main() {
  int i, j, a[N+1];
  for(a[1] = 0, i = 2;  i <= N; i++) {
    a[i] = 1;
  }
  for(i = 2; i <= N/2; i++) {
    /* if a[i] is not prime, than all of its multiples have already been zeroed */
    if(a[i]) {
      for(j = 2; j <= N/i; j++) {
        a[i*j] = 0;
      }
    }
  }
  for(i = 1; i <= N; i++) {
    if(a[i]) {
      printf("%7d",i);
    }
  }
  printf("\n");
  printf("\nsizeof int: %lu \n", sizeof(int));
}
