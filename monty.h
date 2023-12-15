#ifndef MONTY_H
#define MONTY_H

/****************
 * std Libraries
 ****************/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


/*******************
 * Compix DataTypes
 *******************/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *top;


/**********************
 * Functions Prototype
 **********************/
void (*get_op_func(char *))(stack_t **, unsigned int);
void op_handler(char *);
void free_stack(void);
void print_err(int status, ...);
int _isdigit(char *);
stack_t *create_node(int);

/* operators prototype */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);

#endif /* MONTY_H */
