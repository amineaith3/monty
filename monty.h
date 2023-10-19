#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>



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



extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);



/* files functions */

void open_file(char *file_name);
int parse_file(char *buffer, int number_line, int format_parse);
void read_file(FILE *);
int len_chars(FILE *);
void find_function(char *, char *, int, int);

/* stacks functions*/

stack_t *create_node(int position);
void nodes_free(void);
void stack_to_print(stack_t **, unsigned int);
void add_to_the_stack(stack_t **, unsigned int);
void add_to_the_queue(stack_t **, unsigned int);

void call_function(op_func, char *, char *, int, int);

void print_in_top(stack_t **, unsigned int);
void pop_from_top(stack_t **, unsigned int);
void nop_nodes(stack_t **, unsigned int);
void swap_in_nodes(stack_t **, unsigned int);

/*Math functions on nodes*/
void add_in_nodes(stack_t **, unsigned int);
void sub_in_nodes(stack_t **, unsigned int);
void div_in_nodes(stack_t **, unsigned int);
void mul_in_nodes(stack_t **, unsigned int);
void mod_in_nodes(stack_t **, unsigned int);

/*String functions*/
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);

/*Error hanlding functions*/
void code_to_error_1(int code_error, ...);
void code_to_error_2(int code_error, ...);
void code_to_error_string(int code_error, ...);
void rot_error(stack_t **, unsigned int);

#endif
