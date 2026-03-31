/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:04 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 21:39:28 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	px(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	return (1);
}

void	exec_px(t_stack **a, t_stack **b, t_counter *counter, char c)
{
	if (px(a, b) && counter->print)
	{
		if (c == 'a')
		{
			write(counter->print, "pa\n", 3);
			counter->pa++;
			return ;
		}
		write(counter->print, "pb\n", 3);
		counter->pb++;
	}
}
