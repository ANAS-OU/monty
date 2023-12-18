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
/* get_op_func.c */
void (*get_op_func(char *))(stack_t **, unsigned int);

/* open_file.c */
void open_file(char *);

/* op_handler.c */
void op_handler(char *, char *, unsigned int, int);
stack_t *create_node(int);
void add_to_queue(stack_t **new_node, unsigned int line_number);

/* free_stack.c */
void free_stack(void);

/* _isdigit.c */
int _isdigit(char *);

/* operators_1.c */
void add_node(stack_t **, unsigned int);
void print_all(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void remove_top(stack_t **, unsigned int);
void swap_top(stack_t **, unsigned int);

/* operators_2.c */
void add_top(stack_t **, unsigned int);
void do_none(stack_t **, unsigned int);
void sub_top(stack_t **, unsigned int);
void div_top(stack_t **, unsigned int);
void mul_top(stack_t **, unsigned int);

/* operators_3.c */
void mod_top(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rot_left(stack_t **, unsigned int);
void rot_right(stack_t **, unsigned int);

/* print_err.c */
void err_1(int status, ...);
void err_2(int status, ...);

#endif /* MONTY_H */
