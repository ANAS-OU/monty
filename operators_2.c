#include "monty.h"

/**
 * add - a function that adds the top
 * two elements of the stack
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void add(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(2, line_number);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n += tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}


/**
 * nop - a function that doesn’t do anything.
 * @top: last_node.
 * @line_number: readed line number.
 *
 * Return: nothing.
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	(void)top;
}
