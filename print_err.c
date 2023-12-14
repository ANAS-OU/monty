#include "monty.h"

/**
 * print_err - a function that handles errors
 * @status: the status code
 *
 * Return: nothing
 */
void print_err(int status, ...)
{
	int line_number;
	char *filename;
	va_list args;

	va_start(args, status);
	switch (status)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			filename = va_arg(args, char*);
			fprintf(stderr, "Error: Can't open file %s", filename);
			break;
		case 3:
			line_number = va_arg(args, int);
			filename = va_arg(args, char*);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, filename);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 7:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: can't pint, stack empty", line_number);
			break;
		default:
			break;
	}
	va_end(args);
	free_stack();

	exit(EXIT_FAILURE);
}
