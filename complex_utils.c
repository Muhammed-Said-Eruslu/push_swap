/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:42:16 by mueruslu          #+#    #+#             */
/*   Updated: 2026/02/26 20:05:20 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort_radix(t_stack **a, t_stack **b, t_counter *counter)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				exec_rx(a, counter, 'a');
			else
				exec_px(b, a, counter, 'b');
			j++;
		}
		while (*b)
			exec_px(a, b, counter, 'a');
		i++;
	}
}
