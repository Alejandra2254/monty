#include "monty.h"
/**
 * pint - Function that print the top of the list
 * @stack: stack given by main
 * @line_number: number of line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
