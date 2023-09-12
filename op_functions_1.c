#include "monty.h"
/**
 * push - push element in the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
*/
void push(stack_t **stack, unsigned int line)
{
	(void)line;
	int n = atoi(arg);

	add_dnodeint(stack, n);

}

/**
 * pall - print all element of the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
*/
void pall(stack_t **stack, unsigned int line)
{
	(void)line;

	if (*stack == NULL)
		return;
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * swap - swap the top two elements of the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void swap(stack_t **stack, unsigned int line)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        error_exit_d("L%u: can't swap, stack too short\n", line, EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = (*stack);
    (*stack) = temp;
}

/**
 * add - add the top two elements of the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
 */
void add(stack_t **stack, unsigned int line)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        error_exit_d("L%u: can't add, stack too short\n", line, EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line);
}
