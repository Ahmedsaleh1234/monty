#include "monty.h"
/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @top: stack head
 * @numer: line_number
 * Return: no return
*/
void f_mod(stack_t **top, unsigned int number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	x = h->next->n % h->n;
	h->next->n = x;
	*top = h->next;
	free(h);
}
