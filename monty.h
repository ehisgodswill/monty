#ifndef _MONTY_
#define _MONTY_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representing a stack (or queue)
 * @n: number
 * @prev: pointer to the previous element of the stack (or queue)
 * @next: pointer to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct data_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 *
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  data_t;
extern data_t data;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
/* Array */
void f_push(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);

/* Math */
void f_add(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);

/* String */
void f_pall(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);

/* Stack */
void addnode(stack_t **head, int n);
void f_stack(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);

#endif
