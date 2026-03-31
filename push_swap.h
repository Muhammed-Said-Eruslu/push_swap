/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:06:08 by mueruslu          #+#    #+#             */
/*   Updated: 2026/03/02 19:53:07 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	print;
}	t_counter;

void	exec_sx(t_stack **a, t_counter *counter, char c);
void	ss(t_stack **a, t_stack **b, t_counter *counter);
void	exec_px(t_stack **a, t_stack **b, t_counter *counter, char c);
void	exec_rx(t_stack **a, t_counter *counter, char c);
void	rr(t_stack **a, t_stack **b, t_counter *counter);
void	exec_rrx(t_stack **a, t_counter *counter, char c);
void	rrr(t_stack **a, t_stack **b, t_counter *counter);

void	sort_simple(t_stack **a, t_stack **b, t_counter *counter);
void	sort_medium(t_stack **a, t_stack **b, t_counter *counter);
void	sort_complex(t_stack **a, t_stack **b, t_counter *counter);
void	sort_adaptive(t_stack **a, t_stack **b, t_counter *counter,
			double disorder);
void	sort_two(t_stack **a, t_counter *counter);
void	sort_three(t_stack **a, t_counter *counter);
void	chunk_sort_a_to_b(t_stack **a, t_stack **b, t_counter *counter,
			size_t size);
void	chunk_sort_b_to_a(t_stack **a, t_stack **b, t_counter *counter);
void	complex_sort_radix(t_stack **a, t_stack **b, t_counter *counter);

double	calculate_disorder(t_stack *a, size_t size);
void	put_complexity(double disorder, int strat);
int		is_sorted(t_stack *a);
void	handle_error(void);
long	ft_atol(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_add_back(t_stack **stack, t_stack *new_node);
int		has_duplicates(t_stack *a);
size_t	stack_size(t_stack *stack);
int		find_min_value(t_stack *stack);
void	push_min_to_b(t_stack **a, t_stack **b, t_counter *counter);
void	scaling(t_stack *a);
int		ft_sqrt(int number);
int		find_max_index_pos(t_stack *stack);

void	*ft_memset(void *s, int c, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	free_stack(t_stack **stack);
void	validate_and_add_to_stack(t_stack **a, char *str, char **split);
void	exit_error(t_stack **a, char **split);
int		parse_arguments(int argc, char **argv, t_stack **a, t_counter *cnt);
void	display_bench_metrics(t_counter *cnt, int strat,
			float initial_disorder);
void	create_and_link_node(t_stack **a, int val, char **split);
void	display_rotate_metrics(t_counter *cnt);
void	init_main_vars(t_stack **a, t_stack **b, t_counter *cnt);

#endif