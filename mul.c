#include "monty.h"
/**
 * mul - multiplies the top two elements of the stack.
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void mul(stack_t **top, unsigned int numer)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", numer);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	x = h->next->n * h->n;
	h->next->n = x;
	*top = h->next;
	free(h);
}
