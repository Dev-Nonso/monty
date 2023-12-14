#include "monty.h"
/**
 *f_sub - sustration
 *@head: head of the stack
 *@counter: line_number
 *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int s_sub, nodes;

	tmp = *head;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(wet.file);
		free(wet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	s_sub = tmp->next->n - tmp->n;
	tmp->next->n = s_sub;
	*head = tmp->next;
	free(tmp);
}
