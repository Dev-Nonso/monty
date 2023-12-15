#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"queue", f_queue},
		{"stack", f_stack},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *con;

	con = strtok(content, " \n\t");
	if (con && con[0] == '#')
		return (0);
	wet.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && con)
	{
		if (strcmp(con, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (con && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, con);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

