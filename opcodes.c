#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
* push - Pushes an element onto the stack
* @stack: A pointer to the stack (doubly linked list)
* @line_number: The current line number in the Monty bytecode file
*
* Return: No return value. If there's an error,
*          the function may exit the program.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	char *argument = strtok(NULL, " \t\n");

	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
