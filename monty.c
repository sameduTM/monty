#include "monty.h"
#include <stdlib.h>
/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on successful execution, or EXIT_FAILURE on errors.
 */
int main(int argc, char *argv[])
{

	stack_t *stack;

	unsigned int line_number;

	char *line;

	size_t len;
	ssize_t read;
    FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;

	line_number = 0;

	line = NULL;

	len = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
	}

	free(line);
	fclose(file);

	return (0);
}
