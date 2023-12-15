#include "monty.h"

/**
 * add_top - a function that adds the top
 * two elements of the stack
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void add_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 1);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n += tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}


/**
 * do_none - a function that doesn’t do anything.
 * @top: last_node.
 * @line_number: readed line number.
 *
 * Return: nothing.
 */
void do_none(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	(void)top;
}

/**
 * sub_top - a function that subtracts the top element of
 * the stack from the second top element of the stack.
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void sub_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 2);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n -= tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}


/**
 * div_top - a function that divides the second top element
 * of the stack by the top element of the stack.
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void div_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 3);

	/* division by zero */
	if (!(*top)->n)
		err_2(2, line_number);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n /= tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}

/**
 * mul_top - a function that multiplies the second top element
 * of the stack with the top element of the stack.
 * @top: last_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void mul_top(stack_t **top, unsigned int line_number)
{
	stack_t *pre_top, *tmp;

	if (!*top || !(*top)->prev)
		err_2(1, line_number, 4);

	tmp = *top;
	pre_top = tmp->prev;
	pre_top->n *= tmp->n;
	pre_top->next = NULL;
	*top = pre_top;

	free(tmp);
}
