#include "monty.h"
/**
 *
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;

	if (head)
		printf("%d\n", head->n);
}
