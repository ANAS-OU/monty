#include "monty.h"

/**
 * _isdigit - a function that checks if a given string
 * contains digits or not.
 * @str: input string
 *
 * Return: 1 if it's a digit, 0 if not
 */
int _isdigit(char *str)
{
	if (!str)
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
