#include "../push_swap.h"

void	normalize(t_stack *a)
{
	int	*array;

	array = malloc(sizeof(int *) * a->size);
	if (!array)
		return ;
	copy_stack_to_array(a, array);
	sort_array(array, a->size);
	index_stack_values(a, array);
	free(array);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	max_bits;

	normalize(a);
	i = 0;
	max_bits = get_max_bits(a->size);
	while (i < max_bits)
	{
		radix_pass(a, b, i);
		i++;
	}
}