#include "monty.h"



/**
 * add_tote_stack - is a function that adds a node to the stack
 * @new_node: pointer to the new node
 * @line: a number representing the line of the op_code
 */

void add_tote_stack(stack **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}



/**
 * stack_to_print - is a function to print the stack
 * @stack: pointer to the stack
 * @line: a number representing the line of the op_code
 */

void stack_to_print(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	(void) line;
	if (stack ==  NULL)
	{
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

}

/**
 * pop_from_top - is a function to pop content from the stack
 * @stack: a pointer to the stack
 * @line: a number to the line of the op_code
 */

void pop_from_top(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		code_to_error_2(7, line);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}



/**
 * print_in_top - is a function to print the content form the top of the stack
 * @stack: is a pointer to the stack
 * @line: is a number to the line of the op_code
 */

void print_in_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		code_to_error_2(6, line);
	}
	printf("%d\n", (*stack)->n);
}
