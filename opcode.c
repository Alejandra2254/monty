#include "monty.h"

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
}