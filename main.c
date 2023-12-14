#include "monty.h"

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

	op_handler(av[1]);

	return (0);
}
