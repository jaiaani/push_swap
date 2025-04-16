#include "../push_swap.h"

void sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rrb(t_stack *b)
{
	rev_rotate(b);
	write(1, "rb\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}