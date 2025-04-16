/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:14:42 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/15 23:46:31 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
