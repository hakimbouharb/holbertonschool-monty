#include "monty.h"
/**
 * main - main finction
 * @argc: argument counter
 * @argv: argument variables
 * Return: success 0   on error 1
*/
char *arg;

int main(int argc, char **argv)
{
    FILE *fd;
    char *buffer = NULL;
    char *op;
    size_t len = 0;
    ssize_t nread = 1;
	unsigned int nline = 1;
	stack_t *top = NULL;
    void (*f)(stack_t **, unsigned int);

	if (argc != 2)
		error_exit_s("USAGE: monty file\n", NULL, EXIT_FAILURE);
	
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		error_exit_s("Error: Can't read from file %s\n", argv[1], EXIT_FAILURE);
	
	
	while ((nread = getline(&buffer, &len , fd)) != -1)
	{
		op = strtok(buffer, DELIM);
		if(op == NULL)
		{
			nline++;
			continue;
		}
		arg = strtok (NULL, DELIM);
		if (!strcmp(op, "push") && !int_valid(arg))
		{
			fclose(fd);
			free(buffer);
			free_dlistint(top);
			error_exit_d("L%u: usage: push integer\n", nline, EXIT_FAILURE);
		}
		f = get_op_func(op);
		f(&top ,nline);
		nline++;
	} 
	
	fclose(fd);
	free(buffer);
	free_dlistint(top);
	return (0);
}
