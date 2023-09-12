#include "monty.h"
/**
 * add_dnodeint - function that adds a new node
 * at the beginning of a stack_t list
 * @n: number
 * @head: head address
 * Return: new node address
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
		error_exit_s("Error: malloc failed", NULL, EXIT_FAILURE);
	new_node->n = n;
	if (*head == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}