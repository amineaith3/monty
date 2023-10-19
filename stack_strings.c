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




/**
 * rot_l - is a function to rotate the first element to the last place
 * @stack: a pointer to the stack
 * @line: is a number to identify the op_code
 */

void rot_l(stack_t stack, __attribute__((unused))unsigned int line)
{
	stack *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rot_r - is a function to rotate the last elemnt to the first place
 * @stack: is a pointer to the stack
 * @line: is a number to identify the op_code
 */

void rot_r(stack_t stack, __attribute__((unused))unsigned int line)
{
	stack *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
