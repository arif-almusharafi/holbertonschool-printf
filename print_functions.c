#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints one character
 * @c: Character to print
 *
 * Return: 1 on success, or -1 on failure
 */
int print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);

	return (1);
}

/**
 * print_string - Prints a string
 * @str: String to print
 *
 * Return: Number of printed characters, or -1 on failure
 */
int print_string(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";

	i = 0;
	while (str[i] != '\0')
	{
		if (print_char(str[i]) == -1)
			return (-1);
		i++;
	}

	return (i);
}
