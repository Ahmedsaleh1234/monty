#include "monty.h"
/**
  *sub- sustration
  *@top: stack head
  *@number: line_number
  *Return: no return
 */
void sub(stack_t **top, unsigned int number)
{
	stack_t *x;
	int s, n;

	x = *top;
	for (n = 0; x != NULL; n++)
		x = x->next;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	x = *top;
	s = x->next->n - x->n;
	x->next->n = s;
	*top = x->next;
	free(x);
}
