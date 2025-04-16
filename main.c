#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->top;
	printf("Stack (top to bottom):\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	if (!a || !b)
		return (write(2, "Error\n", 6), 1);
	fill_stack_a(a, argc, argv);
	print_stack(a);
	radix_sort(a, b);
	printf("\nsorted!\n");
	print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
