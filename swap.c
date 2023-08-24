#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void f_swap(stack_t **top, unsigned int number)
{
	stack_t *h;
	int ln = 0, s;

	h = *top;
	while (h)
	{
		h = h->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	s = h->n;
	h->n = h->next->n;
	h->next->n = s;
}

