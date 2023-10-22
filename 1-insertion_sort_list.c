#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using Insertion sort algorithm
 * 
 * @list: a pointer to the list's head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *to_swap = *list;
	listint_t *backward_tmp;
	
	while (tmp)
	{
		if ((tmp->n) > (tmp->next->n))
		{
			to_swap = tmp->next;
			swap_list(tmp, to_swap, list);
			while (to_swap->prev && (to_swap->prev->n) > (to_swap->n))
			{
				backward_tmp = to_swap->prev;
				swap_list(backward_tmp, to_swap, list);
				to_swap = to_swap->next;
			}
			print_list(*list);
		}
		tmp = tmp->next;
	}
}

/**
 * swap_list - swaps two nodes
 * 
 * @a: a pointer to node a
 * @b: a pointer to node b
 */
void swap_list(listint_t *tmp, listint_t *to_swap, listint_t **list)
{
	if (tmp->prev != NULL)
		tmp->prev->next = to_swap;
	else
		*list = to_swap;

	if (to_swap->next != NULL)
		to_swap->next->prev = tmp;

	tmp->next = to_swap->next;
	to_swap->prev = tmp;
	to_swap->next = tmp;
	tmp->prev = to_swap;
}

/**
 * check_backward_swap - checks if there should be a backward swap
 *
 * @to_swap: a pointer to a node to check with it's previous node
 *
 * Retrun: 1 if there should be a swap, 0 otherwise
 */
int check_backward_swap(listint_t *to_swap)
{
	if ((to_swap->n) < (to_swap->prev->n))
		return (1);
	return (0);
}
