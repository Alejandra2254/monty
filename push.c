#include "monty.h"
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