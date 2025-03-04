/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move_each.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:35 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:36 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	move_a(t_nest *list, t_ops *ops)
{
	int	i;

	i = 0;
	if (ops->a_ops > 0)
	{
		while (i++ < ops->a_ops)
			ra(list);
	}
	else
	{
		while (i-- > ops->a_ops)
			rra(list);
	}
}

void	move_b(t_nest *list, t_ops *ops)
{
	int	i;

	i = 0;
	if (ops->b_ops > 0)
	{
		while (i++ < ops->b_ops)
			rb(list);
	}
	else
	{
		while (i-- > ops->b_ops)
			rrb(list);
	}
}
