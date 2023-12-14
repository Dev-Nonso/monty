#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, i = 0, flag = 0;

	if (wet.argument)
	{
		if (wet.argument[0] == '-')
			i++;
		for (; wet.argument[i] != '\0'; i++)
		{
			if (wet.argument[i] > 57 || wet.argument[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(wet.file);
			free(wet.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(wet.file);
		free(wet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(wet.argument);
	if (wet.fifo == 0)
		__addnode(head, n);
	else
		__addqueue(head, n);
}
