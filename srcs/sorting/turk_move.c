/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:29 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:30 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

#include <stdio.h>

static void	move_both(t_nest *list, t_ops *ops)
{
	int	i;

	i = 0;
	while (i < ops->a_ops && i < ops->b_ops)
	{
		rr(list);
		i++;
	}
	while (i < ops->a_ops || i < ops->b_ops)
	{
		if (i < ops->a_ops)
			ra(list);
		else
			rb(list);
		i++;
	}
	pa(list);
}

static void	rev_both(t_nest *list, t_ops *ops)
{
	int	i;

	i = 0;
	while (i > ops->a_ops && i > ops->b_ops)
	{
		rrr(list);
		i--;
	}
	while (i > ops->a_ops || i > ops->b_ops)
	{
		if (i > ops->a_ops)
			rra(list);
		else
			rrb(list);
		i--;
	}
	pa(list);
}

static void	move_each(t_nest *list, t_ops *ops)
{
	move_a(list, ops);
	move_b(list, ops);
	pa(list);
}

void	make_move(t_nest *list, t_ops *ops)
{
	if (ops->a_ops > 0 && ops->b_ops > 0)
		move_both(list, ops);
	else if (ops->a_ops < 0 && ops->b_ops < 0)
		rev_both(list, ops);
	else
		move_each(list, ops);
}
