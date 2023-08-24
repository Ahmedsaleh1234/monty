#include "monty.h"
/**
  *rotl- rotates the stack to the top
  *@top: stack head
  *@number: line_number
  *Return: no return
 */
void rotl(stack_t **top,  __attribute__((unused)) unsigned int number)
{
	stack_t *tmp = *top, *x;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	x = (*top)->next;
	x->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = tmp;
	(*top) = x;
}
