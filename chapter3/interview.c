#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int MAX = 10;
  if(argc > 1) {
    MAX = atoi(argv[1]);
    printf("There were %d arguments!\n",argc-1);
    printf("Arg 1 was: %d\n",MAX);
  }
  printf( "test\n");
  int i=0;
  for(i=0; i <= MAX; i++) {
    if((i%2) == 1) {
      printf("%d is odd!\n",i);
    } else {
      printf("%d is Evenz, you fo0l!\n",i);
    }
  }

}
