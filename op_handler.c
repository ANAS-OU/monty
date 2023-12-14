#include "monty.h"

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
	char *opcode, *data, line[LINESIZE];
	void (*handler)(stack_t **stack, unsigned int line_number);
	stack_t *new_node;
	unsigned int line_number;
	int n;

	fp = fopen(filename, "r");
	if (!fp)
		print_err(2, filename);

	line_number = 0;

	while (fgets(line, LINESIZE, fp) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		data = strtok(NULL, " \t\n");

		handler = get_op_func(opcode);
		if (!strcmp(opcode, "push"))
		{
			if (!_isdigit(data))
				print_err(6, line_number);

			n = atoi(data);
			new_node = create_node(n);
			handler(&new_node, line_number);
		}
		else
			handler(&top, line_number);
	}
	fclose(fp);
}
