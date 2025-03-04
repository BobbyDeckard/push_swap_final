/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:21 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:22 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	cl_get_numbers(t_nest *list, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i + 1 < ac)
		(list->nbrs)[i] = ft_atoi(av[i + 1]);
}

int	*cl_init_numbers(t_nest *list, int ac)
{
	int	*numbers;

	numbers = (int *) malloc((ac - 1) * sizeof(int));
	if (!numbers)
		exit_all(list);
	list->size = ac - 1;
	return (numbers);
}
