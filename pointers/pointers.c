#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly.

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
  int i = 0;
  for (; i < strlen(y); i++)
  {
    x[i] = y[i];
  }
  x[i + 1] = NULL;
}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
  while (*str != c && *str != '\0')
  {
    str++;
  }
  if (*str == '\0')
  {
    return NULL;
  }
  return str;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
  char *tempH = haystack;         // used to reset back to ith in loop if wrong substring/string
  char *tempNeedleStart = needle; // used to reset back to ith in loop if wrong substring/string
  // loop until last character in either string or substring found
  while (*haystack != '\0')
  {
    tempH = haystack;
    // if char matches the first char in needle
    if (*tempH == *needle)
    {
      for (; *tempH != '\0' && *needle != '\0' && *tempH == *needle; tempH++, needle++)
      {
      }
      // if needle was found in haystack
      if (*needle == '\0')
      {
        needle = tempNeedleStart;
        return haystack;
      }
      // reset position to starting char where the needle was found.
    }
    needle = tempNeedleStart;
    haystack++;
  }
  return NULL;
}

#ifndef TESTING
int main(void)
{
  // string_copy
  char buffer[1024];
  string_copy(buffer, "hello");
  printf("%s\n", buffer);

  // find_char
  char *found_char1 = find_char("hello", 'e');
  printf("Found char: %s\n", found_char1);
  char *found_char2 = find_char("LambdaSchool", 's'); // should return null or '\0'
  printf("Found char: %c\n", found_char2);

  // find_string
  char *str = "LambdaSchool";
  char *found_string = find_string(str, "lambda");
  printf("Found string: %s\n", found_string);

  char *str2 = "LambdaSchool";
  char *found_string2 = find_string(str2, "School");
  printf("Found string: %s\n", found_string2);

  return 0;
}
#endif
