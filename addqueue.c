#include "monty.h"
/**
 * f_queue - prints the top
 * @top: stack head
 * @coun: line_number
 * Return: no return
*/
void f_queue(stack_t **top, unsigned int coun)
{
	(void)top;
	(void)coun;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @item: new_value
 * @top: head of the stack
 * Return: no return
*/
void addqueue(stack_t **top, int item)
{
	stack_t *new_node, *tmp;

	tmp = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = item;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
