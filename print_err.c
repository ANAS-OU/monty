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
	char *opcode;
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
			line_number = va_arg(args, int);
			opcode = va_arg(args, char*);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pint, stack empty", va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't pop an empty stack", va_arg(args, int));
			break;
		default:
			break;
	}
	va_end(args);
	free_stack();

	exit(EXIT_FAILURE);
}
