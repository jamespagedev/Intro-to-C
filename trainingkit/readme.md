# Training Kit Reference

The purpose of this folder is to document what was in the training kit

## Videos

- Introduction to c: https://www.youtube.com/watch?v=-VzxJwHDFsM
- Memory Module in c: https://www.youtube.com/watch?v=MI_C_Qt4RCM
- How to use pointers in c: https://www.youtube.com/watch?v=uloU0VqOV7k
- Using structs in c: https://www.youtube.com/watch?v=3tBW2Hhocbk
- Class Recording CS13: https://www.youtube.com/watch?v=hEeGfA4BdrY

## Learn

> Learn to describe and use header files, basic types, arrays, strings, flow control, and functions in C

While there are many important topics that fall under the umbrella of C programming, there are a few fundamental concepts that you will likely need to use, regardless of the type of application you are developing. Some concepts, like header files, may be new, depending on what languages you have worked with previously. Others, like data types and functions, are very similar to their counterparts in other languages like JavaScript.

## Header Files

Listed at the top of the program:

```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
```

Each included header file gives access to the functionality declared in that header file.

- Only `#include` the files you need
- Consult the `man` page for the function to see what you want to `#include`
  - If the `man` page doesn’t look right, like it’s for another language, try other manual sections, especially 2 and 3:
    - `man 2 fork`
    - `man 3 printf`

## Types

### Numeric Types

```
// Sample Declarations

int a; // a is an integer
long a; // a is a long integer--holds bigger values
float f; // floating point number, like 3.14159
double f; // double-precision floating point number--holds more precise values
char c; // // 1-byte integer value, or a character
```

Initialization:

```
int a = 12;
float f = 32.9;
```

Implicit and Explicit Type Casting:

```
int a = 5.1;
printf("The value stored in a is %d\n", a); // Output: The value stored in a is 5
//This is as expected.  Integers cannot store decimals, so the value is implicitly type cast from a float to an integer.  The decimal is discarded.

float b = a;
printf("The value stored in b is %f\n", b); // Output: The value stored in b is 5.000000
//This is as expected.  Floats can store the information present in an integer.  The value is implicitly converted to a float, in this case 5.000000

int c = 5/7;
printf("The value stored in c is %d\n", c); // Output: The value stored in c is 0
//This is as expected.  Integer math discards decimals, so 5/7 == 0 in integer-speak.

float d = 5/7;
printf("The value stored in d is %f\n", d); // Output: The value stored in d is 0
//What gives?  5/7 is a decimal number, and floats can do that, right?
//The issue arises from the order of operations in the statement.
//When the compiler sees the '/' operator, it looks at the types of the operands and performs the appropriate operation.
//Because 5 and 7 are both integers, it uses the integer version of divide.
//As in example a, (int) 5 divided by (int) 7 results in (int) 0, then, as above in example b, the value 0 is implicitly type cast from an int to a float.
//The above format is actually how we solve this problem

float e = (float) 5 / 7;
printf("the value stored in e is %f\n", e); // Output: The value stored in e is 0.714286
//This is what we expected.  The compiler sees that one of the operands is a float, and provides a result accordingly.
//You don't need to typecast both operands to get this result, but be careful with order of operations.
// (float)( 5/7 ) will first handle the division as integer math, then typecast the result into a float, resulting in 0.000000 again.
```

## Arrays

```
int a[20];        // array of 20 ints
float f[2][20]; // 2D array, 2 rows of 20 columns of floats
```

Initialization:

```
int a[5] = {4, 7, 2, 9, 3};
int b[2][3] = { { 1,2,3}, {4,5,6} };

// Autosize the array to 3 elements:
int c[] = {10, 50, 100};
```

## Strings

Strings are stored as a pointer to the first element. The string terminates with a NUL (\0) character. That is, a NUL is found at the end of the string.

`char *s; // s is a pointer to a char, or string`

Initialization:

```
char *s = "Hello, world!";

// Or into an array:
char t[] = "This is the secret message";
char *u = t; // t and u both refer to the same string
```

## Functions

```
// Function that accepts an int, a float, and retuns a double

double analyze_data(int d, float f)
{
    double result;

    //... do something very complicated ...

    return result
}

// Function that accepts a string and returns its length:
int string_length(char *s)
{
    // ... compute string length ...
    return len;
}
```

## Flow Control

Works just like javascript for the most part:

```
    if (a == b) {
        // ...
    }

    for (i = 0; i < 10; i++) {
        // ...
    }

    while (!done) { // booleans are "int"s, 0 is false
        // ...
    }

    do {
        // ...
    } while (x < 100);
```

## Follow Along

Write a function that accepts two arguments and returns the sum

```
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(3, 4);

    printf("3 + 4 = %d", result);

    return 0;
}
```

Compiling and running:

```
gcc -Wall -Wextra -o add add.c

./add
```

Note that the `-Wall` flag turns on all warnings. The `-Wextra` flag turns on extra warnings.
