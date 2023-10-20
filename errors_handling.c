#include "monty.h"


/**
 * code_to_error_1 -  prints the appropriate error depepnding on the code erorr
 * @code_error : These are the possible code errors:
 * 1 => user gives other than 1 file to the program, either less or more
 * 2 => the file given can't be neither read or opened by the program
 * 3 => the file contains an invalid instructions
 * 4 => malloc memory issue
 * 5 => when its asked to push something other than an int
 * 6 => the stack is empty to be printed
 * 7 => the stack is empty for pop
 * 8 => the stack is too short for the operations
 */

void code_to_error_1(int code_error, ...)
{
	va_list args;
	char *operation;
	int l_num;

	va_start(args, code_error);
	switch (code_error)
	{
		case 1:
			fprintf(stderr, "USAGE : monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			l_num = va_arg(args, int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * code_to_error_2 - prints the appropriate error depepnding on the code error
 * @code_error : These are the possible code errors:
 * 6 => the stack is empty to be printed
 * 7 => the stack is empty for pop
 * 8 => the stack is too short for the operations
 * 9 => division by zero
 */


void code_to_error_2(int code_error, ...)
{
	va_list args;
	char *operation;
	int l_num;

	va_start(args, code_error);
	switch (code_error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop, stack empty\n", va_arg(args, int));
			break;
		case 8:
			l_num = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}



/**
 * code_to_error_string -  prints the appropriate error depepnding on the code
 * @code_error : These are the possible code errors:
 * 10 => the char to put is out of ASCII range
 * 11 => the car can't be put, stack is empty
 */


void code_to_error_string(int code_error, ...)
{
	va_list args;
	int l_num;

	va_start(args, code_error);
	l_num = va_arg(args, int);

	switch (code_error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}


