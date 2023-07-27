void _div(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        double divisor, dividend;
        /*double hold;*/

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
        /*hold = dividend / divisor;*/
        (*stack)->next->n = dividend / divisor;  /*= (*stack)->n; */
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        free(temp);
}
