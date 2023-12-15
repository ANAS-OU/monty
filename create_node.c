#include "monty.h"

/**
 * create_node - a function that create a new node
 * @data: data for the new node
 *
 * Return: pointer to the created node
 */
stack_t *create_node(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		err_1(4);

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}
