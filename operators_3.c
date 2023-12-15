#include "monty.h"

/**
 * mod_top - a function that computes the rest of the division
 * of the second top element of the stack by the top element
 * of the stack.
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void mod_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 5);

	/* division by zero */
	if (!(*top)->n)
		err_2(2, line_number);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n %= tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}
