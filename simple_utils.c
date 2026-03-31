/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:11 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/02 19:49:58 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	push_min_to_b(t_stack **a, t_stack **b, t_counter *counter)
{
	int		min_val;
	int		size;
	int		pos;
	t_stack	*temp;

	min_val = find_min_value(*a);
	size = stack_size(*a);
	pos = 0;
	temp = *a;
	while (temp && temp->value != min_val)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
	{
		while ((*a)->value != min_val)
			exec_rx(a, counter, 'a');
	}
	else
	{
		while ((*a)->value != min_val)
			exec_rrx(a, counter, 'a');
	}
	exec_px(b, a, counter, 'b');
}

void	sort_three(t_stack **a, t_counter *counter)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		exec_sx(a, counter, 'a');
	else if (first > second && second > third)
	{
		exec_sx(a, counter, 'a');
		exec_rrx(a, counter, 'a');
	}
	else if (first > second && second < third && first > third)
		exec_rx(a, counter, 'a');
	else if (first < second && second > third && first < third)
	{
		exec_sx(a, counter, 'a');
		exec_rx(a, counter, 'a');
	}
	else if (first < second && second > third && first > third)
		exec_rrx(a, counter, 'a');
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_two(t_stack **a, t_counter *counter)
{
	exec_sx(a, counter, 'a');
}
