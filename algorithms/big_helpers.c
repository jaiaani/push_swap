#include "../push_swap.h"

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
		}
		i++;
	}
}

void	copy_stack_to_array(t_stack *a, int *array)
{
	t_node	*node;
	int	i;

	node = a->top;
	i = 0;
	while (node)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
}

void	index_stack_values(t_stack *a, int *array)
{
	t_node *node;
	int	i;

	node = a->top;
	while (node)
	{
		i = 0;
		while (i < a->size)
		{
			if (node->value == array[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

int	get_max_bits(int size)
{
	int bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}
