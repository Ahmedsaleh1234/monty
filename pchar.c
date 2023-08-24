#include "monty.h"
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @top: stack head
 * @number: line_number
 * Return: no return
*/
void pchar(stack_t **top, unsigned int number)
{
	stack_t *h;

	h = *top;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
