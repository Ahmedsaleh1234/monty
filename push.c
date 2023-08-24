#include "monty.h"
#include "monty.h"
/**
 * push - add node to the stack
 * @top: stack head
 * @count: line_number
 * Return: no return
*/
void push(stack_t **top, unsigned int count)
{
	int i, j = 0, fg = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				fg = 1; }
		if (fg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*top);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(top, i);
	else
		addqueue(top, i);
}
