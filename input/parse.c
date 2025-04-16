/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:54:14 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/16 01:54:15 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	if (ft_strlen(str) < 2)
		free_and_exit(a);
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
	int	i;

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
