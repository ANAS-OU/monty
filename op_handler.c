#include "monty.h"

/**
 * op_handler - a function that handles
 * operation code <op_code>
 * @opcode: the opcode
 * @data: the new node data
 * @line_number: the readed line number
 *
 * Return: nothing.
 */
void op_handler(char *opcode, char *data, int line_number)
{
	void (*handler)(stack_t **stack, unsigned int line_number);
	stack_t *new_node;
	int n;

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
