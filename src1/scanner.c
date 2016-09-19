#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "scanner.h"

int c;

/* getc and stdin do not seem to be portable in embedded compilers */
char my_getchar();

static void my_get_num()
{
  while (c=my_getchar(),isdigit(c));
}

static void my_get_op()
{
  while (c=my_getchar(),ispunct(c));
}

void init_scanner()
{
  c=my_getchar();
}

void get_token()
{
  while (c!=EOF) {
     if (isdigit(c)) { my_get_num(); curr_token=num_token; return; }
    if (ispunct(c)) { my_get_op(); curr_token=op_token; return; }
    
    if (!isspace(c)) {
      printf("Error unexpected character\n");
      exit(1);
     }

    c=my_getchar();
  };

  curr_token=end_token;
  return;
}
