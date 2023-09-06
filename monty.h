#ifndef MONTY
#define MONTY

#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/* MACRO */
#define BUFSIZE 1024


/* COMPILING */

/* gcc -Wall -Werror -Wextra -pedantic *.c -o monty */

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* FUNCTION */

void error_exit_s(const char *message, const char *extra_info, int code);
void error_exit_d(const char *message, const int extra_info, int code);
void invalid_opcode(const int line, const char *opcode);
char **parse_monty(char *input);

#endif
