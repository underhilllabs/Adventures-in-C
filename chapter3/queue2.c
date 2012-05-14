#include <stdio.h>
#include <math.h>

#define MAX 100

int queue[MAX+1];
int head, tail;

queue_init() {
  head = 0;
  tail = 0;
}

int is_empty() {
  return head==tail;
}

int remoove() {
  int v = queue[head];
  head++;
  if(head > MAX) {
    head=0;
  }
  return v;
}

put(int v) {
  queue[tail]=v;
  tail++;
  if(tail > MAX) {
    tail = 0;
  }
}

main() {
  int i, j;
  int p;
  p = 1;
  queue_init();
  for(i = 0; i <= 10; i++) {
    for(j=0;j<i;j++) {
      p *= 2;
    }
    put(p);
    p = 1;
  }

  for(i = 0; i <= 10; i++) {
    printf("2^%d = %d\n",i,remoove());
  }
}
  
      
