#include "monty.h"
/**
  *rotr- rotates the stack to the bottom
  *@top: stack head
  *@number: line_number
  *Return: no return
 */
void rotr(stack_t **top, __attribute__((unused)) unsigned int number)
{
	stack_t *cp;

	cp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
