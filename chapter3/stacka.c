#define MAX 10
#include <stdio.h>
#include <stdlib.h>

int stack[MAX+1], head, tail;

stack_init() {
  head = 0;
  tail = 0;
}

/**
 * tail is at last inserted spot, so inc before pushing new element
 */
push(int v) {
  tail++; 
  // circular array
  if(tail > MAX) {
    tail = 0;
  }
  stack[tail] = v;
}

/**
 * tail is at last inserted spot, so pop, then decrement.
 */
int pop() {
  int v = stack[tail];
  tail--;
  return v;
}

int empty() {
  return head==tail;
}

main() {
  int i;
  stack_init();
  for(i = MAX; i > 0; i--) {
    push(i*i);
  }
  
  for(i = 0; i < MAX; i++) {
    printf("%d^2 => %d\n", i+1, pop());
  }
}
