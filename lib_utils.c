/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:48:09 by mueruslu          #+#    #+#             */
/*   Updated: 2026/03/02 19:45:28 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	display_rotate_metrics(t_counter *cnt)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr_fd(cnt->ra, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(cnt->rb, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(cnt->rr, 2);
	write(2, "  rra: ", 7);
	ft_putnbr_fd(cnt->rra, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(cnt->rrb, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(cnt->rrr, 2);
	write(2, "\n", 1);
}

void	init_main_vars(t_stack **a, t_stack **b, t_counter *cnt)
{
	*a = NULL;
	*b = NULL;
	ft_memset(cnt, 0, sizeof(t_counter));
	cnt->print = 1;
}
