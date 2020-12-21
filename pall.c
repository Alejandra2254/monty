#include "monty.h"
/**
 * pall - function that print the list
 * @stack: stack given by main
 * @line_number: number of line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	size_t c = 0;
	stack_t *head = *stack;
	(void) line_number;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		c++;
	}
}
