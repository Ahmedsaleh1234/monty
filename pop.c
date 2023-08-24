#include "monty.h"
/**
 * pop - prints the top
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void f_pop(stack_t **top, unsigned int number)
{
	stack_t *h;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	*top = h->next;
	free(h);
}
