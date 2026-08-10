#include <stdarg.h>
#include "main.h"

/**
 * handle_conversion - Handles one format conversion
 * @specifier: Conversion specifier
 * @args: Variable arguments list
 *
 * Return: Number of printed characters, or -1 on failure
 */
int handle_conversion(char specifier, va_list *args)
{
	int first;
	int second;

	if (specifier == '\0')
		return (-1);
	if (specifier == 'c')
		return (print_char(va_arg(*args, int)));
	if (specifier == 's')
		return (print_string(va_arg(*args, char *)));
	if (specifier == '%')
		return (print_char('%'));

	first = print_char('%');
	if (first == -1)
		return (-1);

	second = print_char(specifier);
	if (second == -1)
		return (-1);

	return (first + second);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of printed characters, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	int printed;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			printed = handle_conversion(format[i], &args);
		}
		else
			printed = print_char(format[i]);

		if (printed == -1)
		{
			va_end(args);
			return (-1);
		}
		count += printed;
		i++;
	}
	va_end(args);
	return (count);
}
