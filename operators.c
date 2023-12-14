#include "monty.h"

/**
 * push - a function that adds a new node to the stack.
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */

void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;

	if (!_isdigit(data))
		print_err(6, line_number);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		print_err(4);

	new_node->n = atoi(data);
	new_node->prev = *top;
	new_node->next = NULL;
	if (*top)
		(*top)->next = new_node;
	*top = new_node;
}

/**
 * pall - function that prints all the values on the stack,
 * starting from the top of the stack.
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *curr;
	(void)line_number;

	curr = *top;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
