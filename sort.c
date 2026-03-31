/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:22:46 by mueruslu          #+#    #+#             */
/*   Updated: 2026/03/02 19:51:00 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five(t_stack **a, t_stack **b, t_counter *counter)
{
	while (stack_size(*a) > 3)
		push_min_to_b(a, b, counter);
	sort_three(a, counter);
	while (*b)
		exec_px(a, b, counter, 'a');
}

void	sort_adaptive(t_stack **a, t_stack **b, t_counter *counter,
	double disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b, counter);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, b, counter);
	else
		sort_complex(a, b, counter);
}

void	sort_simple(t_stack **a, t_stack **b, t_counter *counter)
{
	size_t	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a, counter);
	else
	{
		while (stack_size(*a) > 3)
			push_min_to_b(a, b, counter);
		sort_three(a, counter);
		while (*b)
			exec_px(a, b, counter, 'a');
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_counter *counter)
{
	size_t	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a, counter);
	else if (size <= 5 && size > 2)
		sort_five(a, b, counter);
	else
	{
		chunk_sort_a_to_b(a, b, counter, size);
		chunk_sort_b_to_a(a, b, counter);
	}
}

void	sort_complex(t_stack **a, t_stack **b, t_counter *counter)
{
	size_t	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a, counter);
	else if (size <= 5 && size > 2)
		sort_five(a, b, counter);
	else
		complex_sort_radix(a, b, counter);
}
