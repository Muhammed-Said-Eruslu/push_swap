/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukuruder <ukuruder@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:47:11 by mueruslu          #+#    #+#             */
/*   Updated: 2026/03/02 19:15:10 by ukuruder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_strategy(t_stack **a, t_stack **b, t_counter *cnt, int strat)
{
	if (strat == 4)
		sort_adaptive(a, b, cnt, calculate_disorder(*a, stack_size(*a)));
	else if (strat == 1)
		sort_simple(a, b, cnt);
	else if (strat == 2)
		sort_medium(a, b, cnt);
	else if (strat == 3)
		sort_complex(a, b, cnt);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	print_disorder(float disorder, int strat)
{
	int	integer_part;
	int	decimal_part;

	integer_part = ((int)disorder) * 100;
	decimal_part = (int)((disorder - integer_part / 100.0) * 100);
	if (decimal_part < 0)
		decimal_part *= -1;
	write(2, "[bench] disorder:  ", 19);
	ft_putnbr_fd(integer_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part, 2);
	write(2, "\n", 2);
	put_complexity(disorder, strat);
}

void	display_bench_metrics(t_counter *cnt, int strat, float initial_disorder)
{
	int	total;

	total = cnt->sa + cnt->sb + cnt->ss + cnt->pa + cnt->pb
		+ cnt->ra + cnt->rb + cnt->rr + cnt->rra + cnt->rrb + cnt->rrr;
	print_disorder(initial_disorder, strat);
	write(2, "[bench] total_ops: ", 20);
	ft_putnbr_fd(total, 2);
	write(2, "\n[bench] sa: ", 14);
	ft_putnbr_fd(cnt->sa, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(cnt->sb, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(cnt->ss, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(cnt->pa, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(cnt->pb, 2);
	write(2, "\n", 1);
	display_rotate_metrics(cnt);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_counter	cnt;
	int			strategy;
	float		initial_disorder;

	if (argc < 2)
		return (0);
	init_main_vars(&a, &b, &cnt);
	strategy = parse_arguments(argc, argv, &a, &cnt);
	if (!a)
		return (0);
	scaling(a);
	initial_disorder = calculate_disorder(a, stack_size(a));
	select_strategy(&a, &b, &cnt, strategy);
	if (cnt.print == 2)
		display_bench_metrics(&cnt, strategy, initial_disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
