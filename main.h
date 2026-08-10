#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
int handle_conversion(char specifier, va_list *args);
int print_char(char c);
int print_string(char *str);

#endif
