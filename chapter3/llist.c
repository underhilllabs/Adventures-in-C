#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node *head, *z, *t;

list_init() {
  head = (struct node *) malloc (sizeof *head);
  z =    (struct node *) malloc (sizeof *z);
  head->next = z;
  z->next = z;
}

delete_next(struct node *t) {
  t->next = t->next->next;
}

struct node *insert_after(int v, struct node *t) {
  struct node *x;
  x = (struct node *) malloc (sizeof *x);
  x->val = v;
  x->next = t->next;
  t->next = x;
  return x;
}

int main() {
  int i = 1;
  list_init();
  struct node *cur;
  for(i = 1; i< 10; i++) {
    cur = insert_after(i*i, head);
  }
  cur = head;
  while (cur != z) {
    cur = cur->next;
    printf("%d\n",cur->val);
  }
}
