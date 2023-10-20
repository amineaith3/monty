#include "monty.h"

/**
 * mul_in_nodes - is a function to add the top two elements to a stack
 * @stack: is a pinter to the stack
 * @line: is a number indicating the line of the op_code
 */

void mul_in_nodes(stack_t **stack, unsigned int line)
{
	int sum = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		code_to_error_2(8, line, "mul");
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_in_nodes - is a function to add the top two elements to a stack
 * @stack: is a pinter to the stack
 * @line: is a number indicating the line of the op_code
 */

void mod_in_nodes(stack_t **stack, unsigned int line)
{
	int sum = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		code_to_error_2(8, line, "mul");
	}
	if ((*stack)->n == 0)
	{
		code_to_error_2(9, line);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
