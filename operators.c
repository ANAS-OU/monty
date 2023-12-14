#include "monty.h"

/**
 * push - a function that adds a new node to the stack.
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */

void push(stack_t **new_node, unsigned int line_number)
{
	(void)line_number;

	(*new_node)->prev = top;
	if (top)
		top->next = *new_node;
	top = *new_node;
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

/**
 * pint - function that prints the value of the top stack
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (*top)
	{
		printf("----------\n");
		printf("%d\n", (*top)->n);
		printf("----------\n");
	}
	else
		print_err(7, line_number);
}
