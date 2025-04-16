/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:52:52 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/16 10:06:19 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ra(a);
	else
		while (a->top != target)
			rra(a);
}
