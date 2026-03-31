/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:07:26 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 22:02:31 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sx(t_stack **x)
{
	t_stack	*first;
	t_stack	*second;

	if (!*x || !(*x)->next)
		return (0);
	first = *x;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*x = second;
	return (1);
}

void	exec_sx(t_stack **x, t_counter *counter, char c)
{
	if (sx(x) && counter->print)
	{
		if (c == 'a')
		{
			write(counter->print, "sa\n", 3);
			counter->sa++;
			return ;
		}
		write(counter->print, "sb\n", 3);
		counter->sb++;
	}
}

void	ss(t_stack **a, t_stack **b, t_counter *cnt)
{
	int	a_ok;
	int	b_ok;

	a_ok = sx(a);
	b_ok = sx(b);
	if (!cnt->print || (!a_ok && !b_ok))
		return ;
	if (a_ok && b_ok)
	{
		write(cnt->print, "ss\n", 3);
		if (cnt->print == 2)
			cnt->ss++;
	}
	else if (a_ok)
	{
		write(cnt->print, "sa\n", 3);
		if (cnt->print == 2)
			cnt->sa++;
	}
	else if (b_ok)
	{
		write(cnt->print, "sb\n", 3);
		if (cnt->print == 2)
			cnt->sb++;
	}
}
