#include "sort.h"

/**
 * selection_sort - uses the algorithm of selection sort
 * to sort any array or list
 *
 * @array: a pointer to the unsorted array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, check_smallest, index;
	int sort_check = 1;

	while (sort_check == 1)
	{
		i = 0;
		j = 0;
		while (i < size - 1)
		{
			check_smallest = array[i];
			swab_check = 1;
			while (j < size - 1)
			{
				if (array[j] < check_smallest)
				{
					check_smallest = array[j];
					index = j;
					swab_check = 0;
				}
				j++;
			}
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			i++;
		}
		if (swab_check == 1)
			sort_check = 0;
	}
}
