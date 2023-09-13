#include "monty.h"

/**
 * read_and_execute_instructions - Read and execute Monty instructions
 * @fd: File pointer
 */
void read_and_execute_instructions(FILE *fd)
{
	char *buffer = NULL, *op;
	size_t len = 0;
	ssize_t nread = 1;
	unsigned int nline = 1;
	stack_t *top = NULL;
	void (*f)(stack_t **, unsigned int);

	while ((nread = getline(&buffer, &len, fd)) != -1)
	{
		op = strtok(buffer, DELIM);
		if (op == NULL || op[0] == '#')
		{
			nline++;
			continue;
		}
		arg = strtok(NULL, DELIM);
		if (!strcmp(op, "push") && !int_valid(arg))
		{
			fclose(fd);
			free(buffer);
			free_dlistint(top);
			error_exit_d("L%u: usage: push integer\n", nline, EXIT_FAILURE);
		}

		f = get_op_func(op);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", nline, op);
			fclose(fd);
			free(buffer);
			free_dlistint(top);
			exit(EXIT_FAILURE);
		}
		f(&top, nline);
		nline++;
	}

	fclose(fd);
	free(buffer);
	free_dlistint(top);
}
