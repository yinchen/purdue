


#include <stdio.h>
#include "HashTableTemplate.h"

#define MAXWORD 1024

struct WordCount {
  const char * word;
  int count;
};

void usage()
{
  fprintf(stderr, "Usage: wcVoid file\n");
}

int main(int argc, char **argv) {
  if (argc <2) {
    usage();
    exit(1);
  }
  
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    perror("fopen");
    exit(1);
  }

  // Use HashTableTemplate  
  HashTableTemplate<WordCount *> table;

  // Copy from wcVoid.cc and adapt it to use template instead of HashTableVoid
  
}





