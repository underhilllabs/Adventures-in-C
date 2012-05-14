#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};

struct node *head, *t, *z, *tail;

node_init() {
  head = (struct node *) malloc (sizeof *head);
  //z = (struct node *) malloc (sizeof *z);
  head->next = z;
  head->key = 0;
  z = head;
  z->next = z;
  //z->key = 23;
}

insert(int k) {
  t = (struct node *) malloc (sizeof *head);
  t->key = k;
  z->next = t;
  t->next = t;
  z = t;
}

int remoove() {
  int x;
  t = head->next;
  head->next = head->next->next;
  x = t->key;
  free(t);
  return x;
}
int empty() {
  if(head->next == z) {
    return 0;
  } 
  return 1;
}
/* move the next node to front of linked list */
move_next_to_front(struct node *t){
  struct node *x;
  x = t->next;
  t->next = t->next->next;
  x->next = head->next;
  head->next = x;
}

/* Exchange places of nodes after, the nodes passed in.*/
exchange(struct node *u, struct node *v) {
  struct node *x, *y;
  x = u->next;
  u->next = u->next->next;
  
  y = v->next;
  v->next = v->next->next;
  
  y->next = u->next;
  u->next = y;

  x->next = v->next;
  v->next = x;
}

main() {
  node_init();
  int i;
  for(i = 1; i <= 10; i++) {
    insert(i);
  }
  for(i = 0; i < 10; i++) {
    printf("%d\n", remoove() );
  }

  for(i = 1; i <= 10; i++) {
    insert(i);
  }
  printf("Moving %d to front.\n",head->next->next->next->next->next->key);
  move_next_to_front(head->next->next->next->next);

  for(i = 0; i < 10; i++) {
    printf("%d\n", remoove() );
  }

  for(i = 1; i <= 10; i++) {
    insert(i);
  }
  struct node *a, *b;
  a = head->next->next;
  b = head->next->next->next->next->next;
  printf("Exchanging %d with %d.\n",a->next->key, b->next->key);
  exchange(a, b);
  for(i = 0; i < 10; i++) {
    printf("%d\n", remoove() );
  }
}
