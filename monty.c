#include "monty.h"
/**
 * main - main finction
 * @argc: argument counter
 * @argv: argument variables
 * Return: success 0   on error 1
*/
int main(int argc, char **argv)
{
    FILE *fd;
    char *buffer = NULL;
    char *op;
    size_t len = 0;
    ssize_t nread = 1;
    void (*f)(stack_t **, unsigned int);

	if (argc != 2)
		error_exit_s("USAGE: monty file\n", NULL, EXIT_FAILURE);
	
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		error_exit_s("Error: Can't read from file %s\n", argv[1], EXIT_FAILURE);

	while (nread > 0)
	{
		nread = getline(&buffer, &len , fd);
		if(nread > 0)
		{
//			printf("%d\n", nread);
		}
	}


	fclose(fd);
	return (0);
}
