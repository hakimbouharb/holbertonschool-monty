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

	if (argc != 2)
		error_exit_s("USAGE: monty file\n", NULL, EXIT_FAILURE);

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		error_exit_s("Error: Can't open file %s\n", argv[1], EXIT_FAILURE);

	read_and_execute_instructions(fd);

	return (EXIT_SUCCESS);
}
