#include "monty.h"
/**
 * pop - Function that remove the top element of the stack
 * @stack: stack given by main
 * @line_number: number of line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	_pop(stack);
}

void _pop(stack_t **stack)
{
	stack_t *tmp = NULL;
	
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
