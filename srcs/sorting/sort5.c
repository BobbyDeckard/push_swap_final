/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:52 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:53 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static void	init_id5(t_stack *stack)
{
	t_stack	*ptr;
	int		id;

	ptr = stack;
	id = -1;
	while (++id < 3)
	{
		ptr->id = id;
		ptr = ptr->next;
	}
	id = -3;
	while (++id < 0)
	{
		ptr->id = id;
		ptr = ptr->next;
	}
}

static t_five	get_smallest(t_stack *stack)
{
	t_stack	*ptr;
	t_five	smol;

	ptr = stack;
	smol.smolst = INT_MAX;
	while (ptr)
	{
		if (ptr->content < smol.smolst)
		{
			smol.smolst = ptr->content;
			smol.ops = ptr->id;
		}
		ptr = ptr->next;
	}
	return (smol);
}

void	init_id4(t_stack *stack)
{
	t_stack	*ptr;
	int		id;

	ptr = stack;
	id = -1;
	while (++id < 3)
	{
		ptr->id = id;
		ptr = ptr->next;
	}
	ptr->id = -1;
}

void	move_smallest(t_nest *list)
{
	t_five	smol;
	int		i;

	smol = get_smallest(list->a_stack);
	i = -1;
	while (++i < ft_abs(smol.ops))
	{
		if (smol.ops > 0)
			ra(list);
		else
			rra(list);
	}
	pb(list);
}

void	sort5(t_nest *list)
{
	init_id5(list->a_stack);
	move_smallest(list);
	init_id4(list->a_stack);
	move_smallest(list);
	sort3(list);
	pa(list);
	pa(list);
}
