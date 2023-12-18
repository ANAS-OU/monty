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


/**
 * print_char - prints the char at the top
 * of the stack, followed by a new line.
 * @top: top_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void print_char(stack_t **top, unsigned int line_number)
{
	int c;

	if (!*top)
		err_2(4, line_number);

	c = (*top)->n;
	if (c < 0 || c > 127)
		err_2(3, line_number);

	putchar(c);
	putchar('\n');
}


/**
 * print_string - prints the string starting at
 * the top of the stack, followed by a new line.
 * @top: top_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void print_string(stack_t **top, unsigned int line_number)
{
	int c;
	stack_t *p;
	(void)line_number;

	p = *top;
	while (p)
	{
		c = p->n;
		if (c <= 0 || c > 127)
			break;
		putchar(c);
		p = p->prev;
	}
	putchar('\n');
}


/**
 * rot_left - rotates the stack to the top.
 * @top: top_node on the stack
 * @line_number: the readed line number.
 *
 * Return: nothing.
 */
void rot_left(stack_t **top, unsigned int line_number)
{
	stack_t *tmp, *btm;
	(void)line_number;

	if (!*top || !(*top)->prev)
		return;

	btm = *top;
	tmp = *top;
	*top = tmp->prev;

	while (btm->prev)
		btm = btm->prev;
	btm->prev = tmp;
	tmp->next = btm;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
}


/**
 * rot_right - rotates the stack to the buttom.
 * @top: top_node on the stack
 * @line_number: the readed line number.
 *
 * Description:
 * The last element of the stack becomes the top
 * element of the stack
 *
 * Return: nothing.
 */
void rot_right(stack_t **top, unsigned int line_number)
{
	stack_t *tmp, *btm;
	(void)line_number;

	if (!*top || !(*top)->prev)
		return;

	btm = *top;
	tmp = *top;

	while (btm->prev)
		btm = btm->prev;
	tmp->next = btm;
	btm->prev = tmp;
	btm->next->prev = NULL;
	btm->next = NULL;

	*top = btm;
}
