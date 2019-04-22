#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of
    characters in the string.

    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
  char *i;
  int length = 0;
  for (i = s; *i != '\0'; i++)
  {
    length++;
  }

  return length;
}

/*
    Write a function that reverses the order of string s and outputs
    the reversed string to the input array rv. The rv array will have
    enough space for the reversed string. Don't forget to terminate
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
  int i = 0;
  char *end = s + string_length(s) - 1;
  for (; end >= s - 1; i++)
  {
    char temp = *end;
    rv[i] = temp;
    end--;
  }
  rv[i] = '\0';
  return rv;
}

#ifndef TESTING
int main(void)
{
  char quote[] = "Four";
  char quote1[] = "Don't forget to be awesome";
  char quote2[] = "a man a plan a canal panama";

  char rv[512];

  printf("length is %d\n", string_length(quote)); // length is 4
  printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
  printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

  return 0;
}
#endif
