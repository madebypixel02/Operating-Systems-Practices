#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 80

/* Error handling */
void panic(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(1);
}

/* List element type */
struct element {
  char *input; /* Pointer to string contents */
  struct element *next; /* Next list element */
}; 

/* inserts a string into the list */
struct element *insert(char *input, struct element *list)
{
	// TODO
	
}

/* Detects if a string is already present in the list */
int repeated(char *input, struct element *list)
{
	// TODO
}

/* Free allocated memory */
void free_list(struct element *list)
{
	// TODO
}

int main()
{
  char input[MAX_STR + 1];
  struct element *list = NULL; // Inits empty list
  int num_strings = 1, hit;

  while (1) {
    printf("%d: ", num_strings);
    scanf("%s", input);

    hit = repeated(input, list);
    if (hit) {
      printf("%s repeated (%d)\n", input, num_strings - hit);
      free_list(list);
      exit(0);
    }
    else list = insert(input, list);

    num_strings++;
  }
}
