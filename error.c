/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:44:36 by ukuruder          #+#    #+#             */
/*   Updated: 2026/03/01 17:30:45 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	write(2, "Error\n", 7);
}

void	exit_error(t_stack **a, char **split)
{
	write(2, "Error\n", 6);
	if (split)
		free_split(split);
	if (a && *a)
		free_stack(a);
	exit(1);
}
