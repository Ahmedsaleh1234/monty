#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void pstr(stack_t **top, unsigned int number)
{
	stack_t *h;
	(void)number;

	h = *top;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
