#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void add(stack_t **top, unsigned int number)
{
	stack_t *h;
	int ln = 0, x;

	h = *top;
	while (h)
	{
		h = h->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	x = h->n + h->next->n;
	h->next->n = x;
	*top = h->next;
	free(h);
}
