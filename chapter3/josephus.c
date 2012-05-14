#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};
int main(int argc, char **argv) {
  int i, N, M;
  struct node *t, *x;

  if(argc > 2) {
    N = atoi(argv[1]);
    M = atoi(argv[2]);
  } else {
    N = 9;
    M = 5;
  }

  t = (struct node *) malloc (sizeof *t);
  t->key = 1;
  x = t;
  for (i = 2; i <= N; i++) {
    t->next = (struct node *) malloc (sizeof *t);
    t = t->next;
    t->key = i;
  }
  /* make linkedlist circular by point back round to head */
  t->next = x;
  while (t != t->next) {
    for(i = 1; i < M; i++) {
      t = t->next;
    }
    printf("%d is todt!\n", t->next->key);
    x = t->next;
    /* cut t->next out of list */
    t->next = t->next->next;
    free(x);
  }
  printf("The %d stands alone!\n",t->key);
  printf("The %d stands alone!\n",t->key);
  printf("Heigh Ho! The Derry-O! The %d stands alone!\n",t->key);
}
    
