#include "monty.h"

wet_t wet = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	size_t len;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	wet.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	content = malloc(MAX_LINE_LENGTH * sizeof(char));
	if (content == NULL)
	{
   		fprintf(stderr, "Memory allocation failed\n");
    		free(content);
    		return (EXIT_FAILURE);
	}

	while (fgets(content, MAX_LINE_LENGTH, file) != NULL)
	{
    		wet.content = content;
    		counter++;

    		len = strlen(content);
    		if (len > 0 && content[len - 1] == '\n')
		{
        		content[len - 1] = '\0';
    		}

    		execute(content, &stack, counter, file);
	}

	free(content);
	free_stack(stack);
	fclose(file);
	return (0);
}
