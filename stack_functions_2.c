#include "monty.h"

/**
 * nop_nodes - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void nop_nodes(stack_s **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}


/**
 * swap_in_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void swap_in_nodes(stack_s **stack, unsigned int line)
{
	stack_s *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		code_to_error_2(8, line, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_in_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void add_in_nodes(stack_s **stack, unsigned int line)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		code_to_error_2(8, line, "add");

	(*stack) = (*stack)->next;
	sums = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_in_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void sub_in_nodes(stack_s **stack, unsigned int line)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		code_to_error_2(8, line, "sub");


	(*stack) = (*stack)->next;
	sums = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_in_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void div_in_nodes(stack_s **stack, unsigned int line)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		code_to_error_2(8, line, "div");

	if ((*stack)->n == 0)
		code_to_error_2(9, line);
	(*stack) = (*stack)->next;
	sums = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
