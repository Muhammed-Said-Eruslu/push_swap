/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 05:12:55 by ukuruder          #+#    #+#             */
/*   Updated: 2026/02/26 20:08:06 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max_index_pos(t_stack *b)
{
	t_stack	*temp;
	int		max_idx;
	int		current_pos;
	int		target_pos;

	if (!b)
		return (0);
	max_idx = -1;
	current_pos = 0;
	target_pos = 0;
	temp = b;
	while (temp)
	{
		if (temp->index > max_idx)
		{
			max_idx = temp->index;
			target_pos = current_pos;
		}
		current_pos++;
		temp = temp->next;
	}
	return (target_pos);
}
