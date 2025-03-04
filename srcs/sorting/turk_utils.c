/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:42 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:43 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static int	get_max_value(int *numbers, int size)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = -1;
	while (++i < size)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}
	return (max);
}

void	init_max(t_nest *list, t_ops *ops, t_ops *temp)
{
	ops->max = get_max_value(list->nbrs, list->size);
	temp->max = ops->max;
}

void	free_ops(t_ops *ops, t_ops *temp)
{
	if (ops)
		free(ops);
	if (temp)
		free(temp);
}

void	exit_turk(t_nest *list, t_ops *ops, t_ops *temp)
{
	free_ops(ops, temp);
	exit_all(list);
}
