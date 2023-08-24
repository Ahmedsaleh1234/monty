#include "monty.h"
/**
 * addnode - add node to the head stack
 * @top: head of the stack
 * @item: new_value
 * Return: no return
*/
void addnode(stack_t **top, int item)
{

	stack_t *new_node, *tmp;

	tmp = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (tmp)
		tmp->prev = new_node;
	new_node->n = item;
	new_node->next = *top;
	new_node->prev = NULL;
	*top = new_node;
}
