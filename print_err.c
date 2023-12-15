#include "monty.h"

/**
 * print_err - a function that handles errors
 * @status: the status code
 *
 * Return: nothing
 */
void print_err(int status, ...)
{
	va_list args;
	int ln;
	char *opc;

	va_start(args, status);
	switch (status)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char*));
			break;
		case 3:
			ln = va_arg(args, int);
			opc = va_arg(args, char*);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: usage: push integer\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(args, int));
			break;
		default:
			break;
	}
	va_end(args);
	free_stack();
	exit(EXIT_FAILURE);
}
