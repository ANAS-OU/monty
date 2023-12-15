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
		err_1(3, line_number, opcode);

	if (!strcmp(opcode, "push"))
	{
		if (!_isdigit(data))
			err_1(6, line_number);

		n = atoi(data);
		new_node = create_node(n);
		handler(&new_node, line_number);
	}
	else
		handler(&top, line_number);
}


/**
 * create_node - a function that create a new node
 * @data: data for the new node
 *
 * Return: pointer to the created node
 */
stack_t *create_node(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		err_1(4);

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}
