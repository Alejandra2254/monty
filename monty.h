#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct help - helpsits function
 * @argument: argumment to push
 */
typedef struct help
{
	char *argument;
} help;
help global;

extern int status;

void error_arguments(void);
void error_openfile(char *filename);
void opcode(stack_t **stack, char *line, int con);
void push(stack_t **stack, unsigned int line_number);
int is_digit(char *string);
void pall(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack);
void nop(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
