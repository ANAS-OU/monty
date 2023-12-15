#include "monty.h"

/**
 * add_node - a function that adds a new node to the stack.
 * @new_node: pointer to the new node
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void add_node(stack_t **new_node, unsigned int line_number)
{
	(void)line_number;

	(*new_node)->prev = top;
	if (top)
		top->next = *new_node;
	top = *new_node;
}


/**
 * print_all - function that prints all the values on the stack,
 * starting from the top of the stack.
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void print_all(stack_t **top, __attribute__((unused))unsigned int line_number)
{
	stack_t *curr;

	curr = *top;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}


/**
 * print_top - function that prints the value of the top stack
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void print_top(stack_t **top, unsigned int line_number)
{
	if (*top)
		printf("%d\n", (*top)->n);
	else
		err_1(7, line_number);
}


/**
 * remove_top - a function that removes the
 * top node in the stack
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void remove_top(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (!*top)
		err_1(8, line_number);

	tmp = *top;
	*top = (*top)->prev;
	free(tmp);
}


/**
 * swap_top - a function swaps the top
 * two elements of the stack.
 * @top: last node
 * @line_number: the readed line number.
 *
 * Return: nothing
 */
void swap_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 0);

	tmp = *top;

	pre_top = tmp->prev;
	tmp->prev = pre_top->prev;
	tmp->next = pre_top;
	pre_top->prev = tmp;

	*top = pre_top;
}
