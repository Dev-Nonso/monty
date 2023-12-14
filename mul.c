#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: head of the stack
 * @counter: line_number
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(wet.file);
		free(wet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->next->n * h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
