#include "monty.h"
/**
 * opcode - function that get the line to identifie the code
 * @stack: stack given by main
 * @line: instruction
 * @con: number of line
 */
void opcode(stack_t **stack, char *line, int con)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if ((strcmp(ops[i].opcode, line)) == 0)
		{
			ops[i].f(stack, con);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",con ,line);
	status = EXIT_FAILURE;
}
