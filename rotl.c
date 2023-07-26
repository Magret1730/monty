#include "monty.h"

/**
 * rotl -  rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = first->next;
	stack_t *current = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	*stack = second;
}


/**
 * rotr -  rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}
