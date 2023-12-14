#include "monty.h"

/**
 * print_error - prints an error message
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(char *estr){
    fprintf(stderr, estr);
	exit(EXIT_FAILURE);
}