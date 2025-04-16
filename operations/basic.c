/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:49:36 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/16 01:51:40 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->top = second;
	if (a->size == 2)
		a->bottom = first;
}

void	rotate(t_stack *a)
{
	t_node	*first;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	a->top->prev = NULL;
	a->bottom->next = first;
	first->prev = a->bottom;
	first->next = NULL;
	a->bottom = first;
}

void	rev_rotate(t_stack *a)
{
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;
	last->next = a->top;
	a->top->prev = last;
	last->prev = NULL;
	a->top = last;
}

void	push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0)
		return ;
	node = a->top;
	a->top = node->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	a->size--;
	node->next = b->top;
	if (b->top)
		b->top->prev = node;
	node->prev = NULL;
	b->top = node;
	b->size++;
}
