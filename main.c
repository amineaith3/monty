#include "monty.h"

stack_t *head = NULL;


/**
 * main - is the main running function
 * @argc: arguments' counting
 * @argv: arguments themselves
 * Return: a 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	nodes_free();
	return (0);
}



/**
 * create_node - is a function to create nodes
 * @position: position to go inside the node
 * Return: the value of the node, or NULL
 */

stack_t *create_node(int position)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		code_to_error_1(4);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = position;
	return (node);
}

/**
 * nodes_free - is a function to free the node
 */

void nodes_free(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}





/**
 * add_tote_queue - Adds a node to the queue.
 * @node: Pointer to the new node.
 * @num: line number of the opcode.
 */
void add_tote_queue(stack_t **node, __attribute__((unused))unsigned int num)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;

}
