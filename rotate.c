/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:09 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 22:12:48 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rx(t_stack **x)
{
	t_stack	*first;
	t_stack	*last;

	if (!*x || !(*x)->next)
		return (0);
	first = *x;
	last = first;
	while (last->next)
		last = last->next;
	*x = first->next;
	(*x)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	return (1);
}

void	exec_rx(t_stack **a, t_counter *counter, char c)
{
	if (rx(a) && counter->print)
	{
		if (c == 'a')
		{
			write(counter->print, "ra\n", 3);
			counter->ra++;
			return ;
		}
		write(counter->print, "rb\n", 3);
		counter->rb++;
	}
}

void	rr(t_stack **a, t_stack **b, t_counter *counter)
{
	int	a_ok;
	int	b_ok;

	a_ok = rx(a);
	b_ok = rx(b);
	if (!counter->print || (!a_ok && !b_ok))
		return ;
	if (a_ok && b_ok)
	{
		write(counter->print, "rr\n", 3);
		counter->rr++;
	}
	else if (a_ok)
	{
		write(counter->print, "ra\n", 3);
		counter->ra++;
	}
	else if (b_ok)
	{
		write(counter->print, "rb\n", 3);
		counter->rb++;
	}
}
