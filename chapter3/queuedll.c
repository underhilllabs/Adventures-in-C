#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
  struct node *prev;
};

struct node *head, *t, *tail;

queue_init() {
  head = (struct node *) malloc (sizeof *head);
  tail = (struct node *) malloc (sizeof *tail);
  head->next = tail;
  head->key = 0;
  tail->next = tail;
  head->prev = head;
  tail->prev = head;
}

insert(struct node *t, int v) {
  struct node *x;
  x = (struct node *) malloc (sizeof *x);
  x->next = t->next;
  t->next = x;
  x->key = v;
  x->prev = t;
  x->next->prev = x;
}

int delete(struct node *t) {
  int v = t->key;
  // check if head or tail
  if(t == head) {
    head = head->next;
  }
  if(t == tail) {
    tail = tail->prev;
  }
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
  return v;
}

main() {
  int i;
  queue_init();
  for(i = 10; i > 0; i--) {
    insert(head,i);
  }
  printf("let's delete some\n");
  for(i = 0; i < 10; i++) {
    printf("%d\n",delete(tail));
  }
}
  

