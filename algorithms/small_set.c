
#include "../push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap(a);
}

void	sort_3(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->value;
	s = a->top->next->value;
	t = a->bottom->value;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		ra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}



void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = find_min_node(a);
	move_to_top(a, min);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = find_min_node(a);
	move_to_top(a, min);
	pb(a, b);
	min = find_min_node(a);
	move_to_top(a, min);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}