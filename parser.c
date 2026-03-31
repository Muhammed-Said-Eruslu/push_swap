/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:12:54 by mueruslu          #+#    #+#             */
/*   Updated: 2026/03/02 17:46:21 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node_to_stack(t_stack **a, int val, char **split)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_error(a, split);
	new_node->value = val;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	ft_add_back(a, new_node);
	if (has_duplicates(*a))
		exit_error(a, split);
}

void	validate_and_add_to_stack(t_stack **a, char *str, char **split)
{
	long	val;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		exit_error(a, split);
	while (str[i + len])
	{
		if (str[i + len] < '0' || str[i + len] > '9')
			exit_error(a, split);
		len++;
	}
	val = ft_atol(str);
	if (len > 11 || val < INT_MIN || val > INT_MAX)
		exit_error(a, split);
	add_node_to_stack(a, (int)val, split);
}

static int	check_and_set_flag(char *arg, t_counter *cnt, int *strategy)
{
	if (ft_strcmp(arg, "--simple") == 0)
		*strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		*strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		*strategy = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		*strategy = 4;
	else if (ft_strcmp(arg, "--bench") == 0)
		cnt->print = 2;
	else
		return (0);
	return (1);
}

static void	process_split(char *arg, t_stack **a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		exit_error(a, split);
	j = 0;
	while (split[j])
	{
		validate_and_add_to_stack(a, split[j], split);
		j++;
	}
	free_split(split);
}

int	parse_arguments(int argc, char **argv, t_stack **a, t_counter *cnt)
{
	int	i;
	int	strategy;

	i = 1;
	strategy = 4;
	while (i < argc)
	{
		if (!check_and_set_flag(argv[i], cnt, &strategy))
			process_split(argv[i], a);
		i++;
	}
	return (strategy);
}
