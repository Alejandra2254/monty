#include "monty.h"
/**
 * push - function that push each node
 * @stack: stack given by main
 * @line_number: number of line
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = atoi(global.argument);

	if (isdigit(n) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!add_node(stack, atoi(global.argument)))
		exit(EXIT_FAILURE);
}
/**
 * add_node - function that add node
 * @stack: stack given by main
 * @n: data
 * Return: number
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;

	return (new);
}
