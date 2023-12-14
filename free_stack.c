#include "monty.h"

/**
 * free_stack - a function that frees the stack.
 *
 * Return: nothing.
 *
 */
void free_stack(void)
{
	stack_t *tmp;

	while (top)
	{
		tmp = top;
		top = top->prev;
		free(tmp);
	}
}
