/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:45 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:47 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static int	*init_array(t_nest *list, int *ptr)
{
	int	*sort;

	sort = (int *) malloc(list->size * sizeof(int));
	if (!sort)
	{
		if (ptr)
			free(ptr);
		exit_all(list);
	}
	return (sort);
}

static int	bubble(int *sort, int size)
{
	int	i;
	int	temp;
	int	swaps;

	i = -1;
	swaps = 0;
	while (++i + 1 < size)
	{
		if (sort[i] > sort[i + 1])
		{
			temp = sort[i];
			sort[i] = sort[i + 1];
			sort[i + 1] = temp;
			swaps++;
		}
	}
	return (swaps);
}

static void	bubblesort(int *sort, int size)
{
	int	swaps;

	swaps = 1;
	while (swaps)
		swaps = bubble(sort, size);
}

static void	get_pos(int *sort, int *nbrs, int *pos, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (sort[i] == nbrs[j])
				pos[j] = i;
		}
	}
}

int	*get_positions(t_nest *list)
{
	int	*nbrs;
	int	*pos;
	int	*sorted;
	int	i;

	nbrs = list->nbrs;
	sorted = init_array(list, NULL);
	pos = init_array(list, sorted);
	i = -1;
	while (++i < list->size)
		sorted[i] = nbrs[i];
	bubblesort(sorted, list->size);
	get_pos(sorted, nbrs, pos, list->size);
	free(sorted);
	return (pos);
}
