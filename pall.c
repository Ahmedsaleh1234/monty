#include "monty.h"
#include "monty.h"
/**
 * pall - prints the stack
 * @top: stack head
 * @count: no used
 * Return: no return
*/
void pall(stack_t **top, unsigned int count)
{
	stack_t *tmp;
	(void)count;

	tmp = *top;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
