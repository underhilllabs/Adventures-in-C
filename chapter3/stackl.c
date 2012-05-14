#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node *head, *t, *tail;

stack_init() {
  head = (struct node *) malloc(sizeof *head);
  tail = (struct node *) malloc(sizeof *tail);
  head->next = tail;
  tail->next = tail;
  head->val = 0;
}
push(int v) {
  t = (struct node *) malloc(sizeof *t);
  t->val = v;
  t->next = head->next;
  head->next = t;
}

int pop() {
  int v;
  t = head->next;
  head->next = head->next->next;
  v = t->val;
  free(t);
  return v;
}

main() {
  int i;
  stack_init();
  for(i = 10; i > 0; i--) {
    push((i)*(i));
  }

  for(i=0; i < 10; i++) {
    printf("%d^2 => %d\n", i+1, pop());
  }
}
