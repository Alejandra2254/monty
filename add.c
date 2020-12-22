#include "monty.h"
/**
 * add - Function that adds the top two elements of the stack
 * @stack: stack given by main
 * @line_number: number of line
 */
void add(stack_t **stack, unsigned int line_number)
{
	int data1, data2, num;

		if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		status = EXIT_FAILURE;
		return;
	}

	data1 = (*stack)->n;
	data2 = (*stack)->next->n;
	num = data1 + data2;

	_pop(stack);
	_pop(stack);
	add_node(stack, num);
}
