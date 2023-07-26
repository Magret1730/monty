#include "monty.h"

/**
 * division -  subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	double divisor, dividend;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = (*stack)->n;
	dividend = (*stack)->next->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n = dividend / divisor;  /* /= (*stack)->n; */
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * mul - function that performs a multiplication operation
 * on the top two elements of a stack.
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int multiplied_result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	multiplied_result = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = multiplied_result;
}

/**
 * mod -  finds the mod of the top element of the stack
 * from the second top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: argv[1]
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int divisor, dividend;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = (int)(*stack)->n;
	dividend = (int)(*stack)->next->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = dividend % divisor;  /* /= (*stack)->n; */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * pchar - prints the char  at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: file wherethe push opcode isexecuted
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((current->n) < 0 || (current->n) > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(current->n));
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: file wherethe push opcode isexecuted
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if ((*stack) == NULL)
		printf("\n");
	if ((*stack) != NULL)
	{
		while (current->n != 0 && current->n >= 1 && current->n <= 127)
		{
			printf("%c", (char)(current->n));
			current = current->next;
		}
		printf("\n");
	}
}
