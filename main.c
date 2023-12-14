#include "monty.h"
data_t data = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: arguments vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	data.file = file;
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		data.content = content;
		counter++;
		if (read_line > 0)
			execute(content, &stack, counter, file);

		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
