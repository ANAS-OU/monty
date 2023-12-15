#include "monty.h"

/**
 * get_op_func - function that returns a pointer
 * to the function that corresponds to the operator
 * @opcode: a given opcode.
 *
 * Return: operation result.
 */

void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, opcode))
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
