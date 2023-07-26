#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: file wherethe push opcode isexecuted
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (current)->n);
}

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the top of the stack.
 * @value_to_push: The line number in the file wherethe push opcode isexecuted
 */
void push(stack_t **stack, int value_to_push)
{
	/* Check if the value already exists in the stack */
	stack_t *new_node;  /* *current = *stack,*/

	/*
	 * while (current)
	{
		if (current->n == value_to_push)
			return;
		current = current->next;
	}
	*/
	/*Assuming the integer to push is given as a global variable `value_to_push`*/
	if ((*stack) == NULL)
		return;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value_to_push;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees all the nodes in the stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL; /* Reset the stack to an empty state */
}
