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
  if (*s == '\0')
  {
    return rv;
  }
  /* 1st Pass Solution
  char *end = s + string_length(s) - 1; // last character
  char *t2 = rv;
  while (end >= s - 1)
  {
    // char temp = *end;
    // *t2 = temp;
    // *end = *t2;
    // *t2 = temp;
    // end--;
    // t2++;

    *t2 = *end; // <-- Just this
    end--;
    t2++;
  }
  t2 = '\0';
  return rv;
  */

  // 2nd Pass Solution
  int i = 0;
  char *end = s + string_length(s) - 1;
  for (; end >= s - 1; i++)
  {
    rv[i] = *end;
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
