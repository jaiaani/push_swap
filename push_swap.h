/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:15 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/16 00:04:11 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libs/libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int	size;
}		t_stack;

t_stack *create_stack(void);
t_node	*create_node(int value);
void	fill_stack_a(t_stack *a, int argc, char *argv[]);
void    free_stack(t_stack *stack);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	rev_rotate(t_stack *a);
void	push(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
#endif
