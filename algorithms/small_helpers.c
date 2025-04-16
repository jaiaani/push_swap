#include "../push_swap.h"

void	*find_min_node(t_stack *a)
{
	t_node	*min;
	t_node	*curr;

	min = a->top;
	curr = a->top;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	move_to_top(t_stack *a, t_node *target)
{
	int		pos;
	t_node	*curr;

	pos = 0;
	curr = a->top;
	while (curr && curr != target)
	{
		curr = curr->next;
		pos++;
	}
	if (pos <= a->size / 2)
		while (a->top != target)
			rotate(a);
	else
		while (a->top != target)
			rev_rotate(a);
}