#include <stdio.h>

main() {
  int letters[26], c, i, j;

  // initialize the letters array
  for(i = 0; i < 26; i++) {
    letters[i] = 0;
  }

  // read in text and tally letters
  while((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      letters[c-'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      letters[c-'A']++;
    }
  }

  // print histogram
  // Should be normalized
  for(i = 0; i < 26; i++) {
    printf("%c: ",i+'a');
    for(j = 0; j < letters[i]; j++) {
      putchar('*');
    }
    putchar('\n');
  }
      
}

