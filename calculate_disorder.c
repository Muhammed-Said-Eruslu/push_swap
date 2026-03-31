/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_disorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:46:32 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/02 19:51:43 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_stack *a, size_t size)
{
	long	mistakes;
	long	total_pairs;
	t_stack	*current_i;
	t_stack	*current_j;

	mistakes = 0;
	total_pairs = 0;
	current_i = a;
	if (size <= 1)
		return (0.0);
	while (current_i != NULL)
	{
		current_j = current_i->next;
		while (current_j != NULL)
		{
			total_pairs++;
			if (current_i->value > current_j->value)
				mistakes++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	return ((double)mistakes / total_pairs);
}

void	put_complexity(double disorder, int strat)
{
	write(2, "[bench] strategy: ", 19);
	if (strat == 4)
	{
		if (disorder < 0.2)
			write(2, "Adaptive / O(n²)", 18);
		else if (disorder >= 0.2 && disorder < 0.5)
			write(2, "Adaptive / O(n√n)", 20);
		else if (disorder >= 0.5)
			write(2, "Adaptive / O(n log n)", 22);
	}
	else if (strat == 3)
		write(2, "COMPLEX / O(n log n)", 21);
	else if (strat == 2)
		write(2, "MEDIUM / O(n√n)", 18);
	else
		write(2, "SIMPLE / O(n²)", 16);
	write(2, "\n", 2);
}
