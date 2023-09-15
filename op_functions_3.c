#include "monty.h"
/**
 * sub - sub subtracts the top element from the second top element
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void sub(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't sub, stack too short\n", line, EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line);
}
/**
 * mul - multiplies the second top element with the top element of the stack
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void mul(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't mul, stack too short\n", line, EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line);
}
/**
 * _div -  divides the second top element by the top element of the stack
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void _div(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't div, stack too short\n", line, EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		error_exit_d("L%u: division by zero\n", line, EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line);
}

/**
 * _mod -  omputes the rest of the division
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't mod, stack too short\n", line, EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		error_exit_d("L%u: division by zero\n", line, EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line);
}
