#include "monty.h"
char *data; /* global variable */

/**
 * op_handler - a function that handles
 * operation code <op_code>
 * @filename: the ByteCodes code filename
 *
 * Return: nothing.
 */
void op_handler(char *filename)
{
	FILE *fp;
	char *opcode, line[LINESIZE];
	void (*handler)(stack_t **stack, unsigned int line_number);
	stack_t *top;
	unsigned int line_number;

	fp = fopen(filename, "r");
	if (!fp)
		print_err(2, filename);

	top = NULL;
	line_number = 0;

	while (fgets(line, LINESIZE, fp) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		data = strtok(NULL, " \t\n");

		handler = get_op_func(opcode);
		handler(&top, line_number);
	}
	fclose(fp);
}
