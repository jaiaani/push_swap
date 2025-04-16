/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:00:50 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/15 20:20:57 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

bool	has_duplicates(t_stack *stack, int value)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		if (curr->value == value)
			return (true);
		curr = curr->next;
	}
	return (false);
}

bool	is_valid_number(char *str)
{
	if (!str || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	free_and_exit(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(EXIT_FAILURE);
}

void	push_bottom(t_stack *stack, t_node *new)
{
	if (!stack->bottom)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	add_number_to_stack(char *str, t_stack *a)
{
	long	n;
	t_node	*node;

	if (!is_valid_number(str))
		free_and_exit(a);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX || has_duplicates(a, (int)n))
		free_and_exit(a);
	node = create_node((int)n);
	if (!node)
		free_and_exit(a);
	push_bottom(a, node);
}

void	process_single_argument(char *str, t_stack *a)
{
	int		i;
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
		free_and_exit(a);
	i = 0;
	while (split[i])
	{
		add_number_to_stack(split[i], a);
		i++;
	}
	free_split(split);
}

void	fill_stack_a(t_stack *a, int argc, char *argv[])
{
	int i;

	if (argc == 2)
		process_single_argument(argv[1], a);
	else
	{
		i = 1;
		while (i < argc)
		{
			add_number_to_stack(argv[i], a);
			i++;
		}
	}
}