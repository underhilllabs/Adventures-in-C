#include <stdio.h>
#include <string.h>
#define MAX 30
#define COLS MAX
#define ROWS MAX

/* Set element to 1 if gcd(i,j) is 1.  Set to O otherwise. */
main() {
  int i, j, k;
  int a[ROWS][COLS];

  /* Set all array elements to 1 with memset. */
  memset(a, 1, sizeof(a[0][0]) * ROWS * COLS);

  /*  */
  for(i = 2; i < MAX/2; i++) {
    for(j = i; j < MAX; j+=i) {
      /* 1: Loop thru i's multiples and zero out j with kth multiple of i. */
      /* Start at current j, as all multiples of i < j have been covered. */
      for(k = j; k < MAX; k+=i) {
        a[k][j] = 0;
        a[j][k] = 0;
      }
    }
  }
  /* Print out the gcd Matrix. */
  for(i = 2; i < MAX; i++) {
    for(j = 0; j < MAX; j++) {
      if(a[i][j]) {
        printf("%d,%d are relatively prime.\n",i,j);
      }
    }
  }
}


/* gcd(int **a, int size) { */
/*   int i, j, k; */
/*   /\* int a[ROWS][COLS]; *\/ */

/*   /\* Set all array elements to 1 with memset. *\/ */
/*   memset(a, 1, sizeof(a[0][0]) * size * size); */

/*   /\*  *\/ */
/*   for(i = 2; i < size/2; i++) { */
/*     for(j = i; j < size; j+=i) { */
/*       /\* 1: Loop thru i's multiples and zero out j with kth multiple of i. *\/ */
/*       /\* Start at current j, as all multiples of i < j have been covered. *\/ */
/*       for(k = j; k < size; k+=i) { */
/*         a[k][j] = 0; */
/*         a[j][k] = 0; */
/*       } */
/*     } */
/*   } */

/* } */
