#include "monty.h"
/**
 * error_arguments - Error about number of arguments
 */
void error_arguments(void)
{
	write(2, "USAGE: monty file\n", 19);
	exit(EXIT_FAILURE);
}
/**
 * error_openfile - The file couldn't open
 * @filename: name of the file
 */
void error_openfile(char *filename)
{
	int i = 0;

	while (filename[i])
		i++;
	write(2, "Error: Can't open file ", 24);
	write(2, filename, i);
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}
int status = 0;
/**
 * main - Entry point
 * Monty Project written by Alejandra
 * @argc: number of arguments.
 * @argv: array of pointers to each argument.
 * Return: 0 in success.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *buff = NULL, *line;
	size_t len = 0;
	stack_t *stack = NULL;
	ssize_t readfile;
	int con = 0;

	if (argc != 2)
		error_arguments();
	file = fopen(argv[1], "r");
	if (!file)
		error_openfile(argv[1]);
	while ((readfile = getline(&buff, &len, file)) != -1)
	{
		if (*buff == '\n')
		{
			continue;
		}
		line = strtok(buff, " \t\n");
		con++;
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, line, con);
	}
	free(buff);
	fclose(file);
	free_stack(stack);
	exit(status);
}
