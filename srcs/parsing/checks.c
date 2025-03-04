/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:10 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:11 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	check_duplicates(t_nest *list)
{
	int	*numbers;
	int	i;
	int	j;

	numbers = list->nbrs;
	i = -1;
	while (++i + 1 < list->size)
	{
		j = i;
		while (++j < list->size)
		{
			if (numbers[i] == numbers[j])
				input_error(list);
		}
	}
}

void	check_args(t_nest *list, int ac, char **av)
{
	if (ac == 2)
		check_str(list, av[1]);
	else
		check_cl(list, ac, av);
	check_duplicates(list);
}
