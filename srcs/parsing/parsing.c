/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:25 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:26 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	input_error(t_nest *list)
{
	ft_putstr_fd("Error\n", 2);
	exit_all(list);
}

void	parse(t_nest *list, int ac, char **av)
{
	int	i;

	check_args(list, ac, av);
	list->pos = get_positions(list);
	i = 0;
	list->a_stack = new_node(list, i);
	while (++i < list->size)
		add_back(list->a_stack, new_node(list, i));
}
