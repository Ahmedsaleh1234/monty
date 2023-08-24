#include "monty.h"
/**
 * f_pint - prints the top
 * @top: stack head
 * @coun: line_number
 * Return: no return
*/
void f_pint(stack_t **top, unsigned int coun)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", coun);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
