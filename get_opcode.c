#include "monty.h"

/**
 * get_op_func - Selects the appropriate function to perform the operation.
 * @opcode: The operator passed as an argument.
 *
 * Return: A pointer to the appropriate function that performs the operation.
 *         If the operator is not recognized, it returns NULL.
 */

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	invalid_opcode(nline, opcode);
	return (NULL);
}
/**
 * int_valid - function that check if str are intier
 * @str: sting to check it
 * Return: 1 success
*/

int int_valid(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-' && str[i] != '+'))
		{
			return (0);
		}
		return (1);
	}
}
