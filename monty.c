#include "monty.h"
/**
 * main - main finction
 * @argc: argument counter
 * @argv: argument variables
 * Return: success 0   on error 1
*/
int main(int argc, char **argv)
{
	int fd;
	const char *file_name = argv[1];


	if (argc != 2)
		error_exit_s("USAGE: monty file\n", NULL, EXIT_FAILURE);
	
//	fd = open(file_name, O_RDONLY);
//	if (fd == -1)
//		error_exit_s("Error: Can't read from file %s\n", file_name, 98);



	return (0);
}
