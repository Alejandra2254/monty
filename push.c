#include "monty.h"
/**
 * push - function that push each node
 * @stack: stack given by main
 * @line_number: number of line
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n = global.argument;

	if (is_digit(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	if (!add_node(stack, atoi(global.argument)))
	{
		status = EXIT_FAILURE;
		return;
	}
}
/**
 * is_digit - Function that checks if is digit or not
 * @string: string to verify
 * Return: 1 if is digit 0 if not.
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
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
/**
 * free_stack - free linked list
 * @stack: pointer head
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
