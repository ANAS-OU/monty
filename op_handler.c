#include "monty.h"

/**
 * op_handler - a function that handles
 * operation code <op_code>
 * @opcode: the opcode
 * @data: the new node data
 * @ln: the readed line number
 * @is_queue: boolean to check is it a queue.
 *
 * Return: nothing.
 */
void op_handler(char *opcode, char *data, unsigned int ln, int is_queue)
{
	void (*handler)(stack_t **stack, unsigned int line_number);
	stack_t *new_node;
	int n;

	handler = get_op_func(opcode);

	if (!handler)
		err_1(3, ln, opcode);

	if (!strcmp(opcode, "push"))
	{
		if (is_queue)
			handler = add_to_queue;

		if (!_isdigit(data))
			err_1(6, ln);

		n = atoi(data);
		new_node = create_node(n);
		handler(&new_node, ln);
	}
	else
		handler(&top, ln);
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


/**
 * add_to_queue - a function that adds new nodes in the
 * front of the stack.
 * @new_node: added node to the queue
 * @line_number: readed line number.
 *
 * Return: nothing.
 */
void add_to_queue(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (!top)
		top = *new_node;
	else
	{
		tmp = top;
		while (tmp->prev)
			tmp = tmp->prev;

		(*new_node)->next = tmp;
		tmp->prev = *new_node;
	}
}
