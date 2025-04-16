#include "../push_swap.h"

void sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}


void ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}


void pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
