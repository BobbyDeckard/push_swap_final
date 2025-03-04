/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:00 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:01 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static int	get_mid(t_nest *list, int divider)
{
	t_stack	*ptr;
	int		mid;
	int		max_pos;

	max_pos = list->size / divider;
	ptr = list->a_stack;
	while (ptr->pos != max_pos)
		ptr = ptr->next;
	mid = ptr->content;
	return (mid);
}

static void	quicksort(t_nest *list, int divider)
{
	t_stack	*ptr;
	int		size;
	int		mid;
	int		i;

	size = stack_size(list->a_stack);
	if (size > 2)
	{
		mid = get_mid(list, divider);
		i = -1;
		while (++i < size)
		{
			ptr = list->a_stack;
			if (ptr->content > mid)
				pb(list);
			else if (ptr->next && ptr->next->content > ptr->content)
				ra(list);
			else if (ptr->pos != 0 && ptr->content <= mid)
				sa(list);
			else
				ra(list);
		}
		quicksort(list, divider * 2);
	}
}

void	turbosort(t_nest *list)
{
	quicksort(list, 2);
	turksort(list);
}
