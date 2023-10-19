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


