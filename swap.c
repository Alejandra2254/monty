#include "monty.h"
/**
 * swap - Swap the top two elements of the stack
 * @stack: stack given by main
 * @line_number: number of line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n;
	
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		status = EXIT_FAILURE;
		return;
	}

	tmp = *stack;
	tmp_n = tmp->n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
