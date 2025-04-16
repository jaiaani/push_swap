
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
		swap(a);
	else if (f > s && s > t)
	{
		swap(a);
		rev_rotate(a);
	}
	else if (f > s && s < t && f > t)
		rotate(a);
	else if (f < s && s > t && f < t)
	{
		swap(a);
		rotate(a);
	}
	else if (f < s && s > t && f > t)
		rev_rotate(a);
}



void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = find_min_node(a);
	move_to_top(a, min);
	push(a, b);
	sort_3(a);
	push(b, a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = find_min_node(a);
	move_to_top(a, min);
	push(a, b);
	min = find_min_node(a);
	move_to_top(a, min);
	push(a, b);
	sort_3(a);
	push(b, a);
	push(b, a);
}