#include "monty.h"


/**
 * p_char - is a function to print the ascii value
 * @stack:  is a pointer to a stack
 * @line: is a number to identify the op_code
 */

void p_char(stack_t stack, unsigned int line)
{
	int code_ascii;

	if (stack == NULL || *stack == NULL)
	{
		code_to_error_string(11, line);
	}
	code_ascii = (*stack)->n;
	if (code_ascii < 0 || code_ascii > 127)
	{
		code_to_error_string(10, line);
	}
	printf("%c\n", code_ascii);
}

/**
 * p_str - is a function to print a string
 * @stack: is a pointer to a stack
 * @line: is a number to identify the op_code
 */

void p_str(stack_t stack, __attribute__((unused))unsigned int line)
{
	int code_ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		code_ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", code_ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
