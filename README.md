# _printf

A custom implementation of the C standard library `printf` function, developed as part of the Holberton School curriculum.

The project focuses on understanding **variadic functions**, **format-string parsing**, **function decomposition**, and low-level output using the `write` system call.

## Description

`_printf` is a simplified version of the standard C `printf` function.

It accepts a format string followed by a variable number of arguments and prints formatted output to the standard output.

## Supported Conversion Specifiers

| Specifier | Description                     |
| --------- | ------------------------------- |
| `%c`      | Prints a single character       |
| `%s`      | Prints a string                 |
| `%d`      | Prints a signed decimal integer |
| `%i`      | Prints a signed integer         |
| `%%`      | Prints the `%` character        |

## Project Structure

```text
holbertonschool-printf/
│
├── _printf.c
├── print_functions.c
├── main.h
└── README.md
```

### `_printf.c`

Contains the main `_printf` function and the conversion-handling logic.

Responsibilities include:

* Processing the format string.
* Detecting `%` conversion specifiers.
* Managing variadic arguments.
* Selecting the appropriate printing function.

### `print_functions.c`

Contains the functions responsible for producing the output.

Main responsibilities include:

* Printing individual characters.
* Printing strings.
* Printing integers.
* Writing output using the `write` system call.

### `main.h`

Contains the function prototypes and required declarations shared across the project files.

## How It Works

The general execution flow is:

```text
_printf()
   │
   ├── Normal character
   │       ↓
   │   print_char()
   │
   └── '%' detected
           ↓
     handle_conversion()
           │
      ┌────┼─────────────┐
      ↓    ↓             ↓
     %c   %s          %d / %i
      │    │             │
      ↓    ↓             ↓
 print_char()       print_number()
 print_string()
```

The implementation uses `va_list` to access arguments passed after the format string.

## Compilation

The project is compiled using GCC with the required compiler flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

To compile the project with a test file:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c test.c -o test
```

Then run:

```bash
./test
```

## Example

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Number: %d\n", 42);
    _printf("Integer: %i\n", -10);
    _printf("Percent: %%\n");

    return (0);
}
```

Example output:

```text
Hello, World!
Character: A
Number: 42
Integer: -10
Percent: %
```

## Technical Concepts

This project provides practical experience with:

* Variadic functions.
* `va_list`, `va_start`, `va_arg`, and `va_end`.
* Pointers.
* Function decomposition.
* Format-string processing.
* Recursion.
* The `write` system call.
* Low-level C programming.
* Memory and lifetime considerations.

## Memory Management

The current implementation does not rely on dynamic memory allocation through `malloc`, `calloc`, or `realloc`.

The printing functions operate directly on the data provided by the caller rather than creating dynamically allocated copies.

This reduces allocation overhead and avoids unnecessary ownership and deallocation requirements.

## Constraints

The implementation follows the constraints of the Holberton School `printf` project, including:

* Written in C.
* Compiled using the required GCC flags.
* Uses low-level output through `write`.
* Uses variadic arguments to process additional parameters.
* Does not simply call the standard library `printf` to perform the main formatting work.

## License

This project was created for educational purposes as part of the Holberton School curriculum.
