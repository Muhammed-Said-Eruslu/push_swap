/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:44:58 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 19:23:00 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scaling(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		scale;

	current = a;
	while (current)
	{
		scale = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				scale++;
			compare = compare->next;
		}
		current->index = scale;
		current = current->next;
	}
}

void	chunk_sort_a_to_b(t_stack **a, t_stack **b, t_counter *counter,
	size_t size)
{
	int	i;
	int	range;

	i = 0;
	range = (ft_sqrt(size) * 14.2) / 10;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			exec_px(b, a, counter, 'b');
			exec_rx(b, counter, 'b');
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			exec_px(b, a, counter, 'b');
			i++;
		}
		else
			exec_rx(a, counter, 'a');
	}
}

void	chunk_sort_b_to_a(t_stack **a, t_stack **b, t_counter *counter)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_index_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
			{
				exec_rx(b, counter, 'b');
			}
		}
		else
		{
			while (max_pos++ < size)
			{
				exec_rrx(b, counter, 'b');
			}
		}
		exec_px(a, b, counter, 'a');
	}
}
