#include "monty.h"

/* global variable head of the stack */
stack_t *top = NULL;

/**
 * main - interpreter for Monty ByteCodes files.
 * @ac: argments count
 * @av: list of argments.
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
		print_err(1);

	open_file(av[1]);

	free_stack();
	return (0);
}
