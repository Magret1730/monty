#include "monty.h"
/**
 * read_and_process_file - Reads the Monty Byte Code file line by line
 * and executes the corresponding opcodes.
 * @file: Pointer to the file stream.
 * Return: Returns 0 on success, and non-zero on failure.
 */
int read_and_process_file(FILE *file)
{
	char line[256], *opcode, *arg;
	unsigned int line_number = 0;
	size_t len;
	int value_to_push;
	stack_t *stack = NULL, *current;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		opcode = strtok(line, " \t");
		if (!opcode || opcode[0] == '#')
			continue; /* Skip empty lines and comments */
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t");
			if (!arg)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				return (EXIT_FAILURE);  /*free_stack(&stack);*/
			}
			value_to_push = atoi(arg);
			current = stack;
			while (current)
			{
				if (current->n == value_to_push)
					return (EXIT_SUCCESS);  /*free_stack(&stack);*/
				current = current->next;
			}
			push(&stack, value_to_push);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);  /*free_stack(&stack);*/
		}
	}
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int status;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	status = read_and_process_file(file);
	fclose(file);
	free_stack(&stack);
	return (status);
}
