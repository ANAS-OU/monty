#include "monty.h"

/**
 * print_err - a function that handles errors
 * @status: the status code
 * @line_number: error line number
 *
 * Return: nothing
 */
void print_err(int status, ...)
{
	va_list args;
	va_start(args, status);

	switch (status)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s", va_arg(args, char*));
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(args, int), va_arg(args, char*));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pint, stack empty", va_arg(args, int));
	}
	va_end(args);
	exit(EXIT_FAILURE);
}
