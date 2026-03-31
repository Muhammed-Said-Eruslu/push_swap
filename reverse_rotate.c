/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:07 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 22:10:10 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrx(t_stack **x)
{
	t_stack	*last;

	if (!*x || !(*x)->next)
		return (0);
	last = *x;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *x;
	(*x)->prev = last;
	*x = last;
	return (1);
}

void	exec_rrx(t_stack **x, t_counter *counter, char c)
{
	if (rrx(x) && counter->print)
	{
		if (c == 'a')
		{
			write(counter->print, "rra\n", 4);
			counter->rra++;
			return ;
		}
		write(counter->print, "rrb\n", 4);
		counter->rrb++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_counter *counter)
{
	int	a_ok;
	int	b_ok;

	a_ok = rrx(a);
	b_ok = rrx(b);
	if (!counter->print || (!a_ok && !b_ok))
		return ;
	if (a_ok && b_ok)
	{
		write(counter->print, "rrr\n", 4);
		counter->rrr++;
	}
	else if (a_ok)
	{
		write(counter->print, "rra\n", 4);
		counter->rra++;
	}
	else if (b_ok)
	{
		write(counter->print, "rrb\n", 4);
		counter->rrb++;
	}
}
