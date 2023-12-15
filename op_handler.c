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
	char *opcode, *data;
	const char *delim = "\t\n ";
	void (*handler)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;
	stack_t *new_node;
	char *buffer = NULL;
	size_t len = 0;
	int n;

	fp = fopen(filename, "r");
	if (!fp || !filename)
		print_err(2, filename);

	line_number = 0;
	while (getline(&buffer, &len, fp) != -1)
	{
		if (!buffer)
			print_err(4);

		line_number++;
		opcode = strtok(buffer, delim);
		data = strtok(NULL, delim);

		if (!opcode)
			print_err(3, line_number, opcode);

		handler = get_op_func(opcode);

		if (!handler)
			print_err(3, line_number, opcode);

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
	free(buffer);
	fclose(fp);
}
