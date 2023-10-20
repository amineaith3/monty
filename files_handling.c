#include "monty.h"

/**
 * open_file - is a function to open files
 * @name: is the file's name
 */

void open_file(char *name)
{
	FILE *fd = fopen(name, "r");

	if (name == NULL || fd == NULL)
	{
		code_to_error_1(2, name);
	}
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - is a function to read files
 * @file: is the file's name
 */

void read_file(FILE *file)
{
	int number_line, format = 0;
	char *buffer = NULL;
	size_t size = 0;

	for (number_line = 0; getline(&buffer, &size, file) != -1; number_line++)
	{
		format = parse_file(buffer, number_line, format);
	}
	free(buffer);
}



/**
 * parse_file - is a function to identify which function to call
 * @buffer: is a line from the file
 * @number: is the number of the line
 * @format: is the identifier of the format, is 0 its a stack, else its a queue
 * Return: Returns 0 or 1
 */

int parse_file(char *buffer, int number, int format)
{
	char *op_code, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
	{
		code_to_error_1(4);
	}
	op_code = strtok(buffer, delimiter);
	if (op_code == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delimiter);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	find_function(op_code, value, number, format);
	return (format);
}



/**
 * find_function - find the appropriate function for the opcode
 * @op_code: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *op_code, char *value, int number, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_tote_stack},
		{"pall", stack_to_print},
		{"pint", print_in_top},
		{"pop", pop_from_top},
		{"nop", nop_nodes},
		{"swap", swap_in_nodes},
		{"add", add_in_nodes},
		{"sub", sub_in_nodes},
		{"div", div_in_nodes},
		{"mul", mul_in_nodes},
		{"mod", mod_in_nodes},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rot_l},
		{"rotr", rot_r},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, op_code, value, number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		code_to_error_1(3, number, op_code);
}


/**
 * call_function - Calls the required function.
 * @function: Pointer to the function that is about to be called.
 * @op_cd: string representing the opcode.
 * @val: string representing a numeric value.
 * @num: line numeber for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func function, char *op_cd, char *val, int num, int form)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op_cd, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			code_to_error_1(5, num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				code_to_error_1(5, num);
		}
		node = create_node(atoi(val) * flag);
		if (form == 0)
			function(&node, num);
		if (form == 1)
			add_tote_queue(&node, num);
	}
	else
		function(&head, num);
}


