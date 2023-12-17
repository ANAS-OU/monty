#include "monty.h"

/**
 * err_1 - a function that handles errors
 * @status: the status code
 *
 * Return: nothing
 */
void err_1(int status, ...)
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


/**
 * err_2 - a function that handles errors
 * @status: the status code
 *
 * opcode:
 * (0) => swap
 * (1) => add
 * (2) => sub
 * (3) => div
 * (4) => mul
 * (5) => mod
 *
 * Return: nothing
 */
void err_2(int status, ...)
{
	va_list args;
	int ln, idx;
	char opcode[6][5] = {
		"swap",
		"add",
		"sub",
		"div",
		"mul",
		"mod"
	};

	va_start(args, status);
	ln = va_arg(args, int);

	switch (status)
	{
		case 1:
			idx = va_arg(args, int);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln, opcode[idx]);
			break;
		case 2:
			fprintf(stderr, "L%d: division by zero\n", ln);
			break;
		case 3:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		case 4:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;

		default:
			break;
	}
	va_end(args);
	free_stack();

	exit(EXIT_FAILURE);
}
