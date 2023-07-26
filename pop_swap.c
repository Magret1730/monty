#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap -  swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
* nop - function that takes the two top stack elements and discard them.
 * @stack: pointer to the stack
 * @line_number: argument vector
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * * sub -  subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        temp = *stack;
        (*stack)->next->n -= (*stack)->n;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        free(temp);
}
