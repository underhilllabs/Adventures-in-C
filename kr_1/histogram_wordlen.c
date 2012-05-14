#include <stdio.h>
#define MAX 30

main() {
  int len[MAX], c, i, j, in, size;
  /* initialize the letters array */
  for(i = 0; i < MAX; i++) {
    len[i] = 0;
  }
  
  in = 0;
  size = 0;
  /* read in text and tally word size */
  while((c = getchar()) != EOF) {
    /* is it a letter or number */
    if((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z') || (c >= '1' && c <= '9')) {
      size++;
    /* apostrophe is a gray area, don't count for length but still inside word */
    } else if (c =='\'') {
      ;
    } else {
      /* 
         We've hit white space or punctuation so we are outside a word
         so, inc the tally of current size of word and start again.
      
         Also, don't tally 0 length words. 
      */
      if (size > 0 && size < MAX) {
        len[size]++;
        size = 0;
      }
    }
      
  }

  /* 
     Print histogram
     @TODO: Should be normalized
  */
  for(i = 1; i < MAX; i++) {
    printf("%2d: ",i);
    for(j = 0; j < len[i]; j++) {
      putchar('*');
    }
    putchar('\n');
  }
      
}

