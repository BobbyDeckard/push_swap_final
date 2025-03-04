/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:08 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:09 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static void	update_ids(t_stack *stack)
{
	t_stack	*ptr;
	int		id;

	ptr = stack;
	id = 0;
	while (ptr)
	{
		ptr->id = id++;
		ptr = ptr->next;
	}
}

static int	get_min_id(t_stack *stack)
{
	t_stack	*ptr;
	int		min;
	int		id;

	ptr = stack;
	min = INT_MAX;
	while (ptr)
	{
		if (ptr->content < min)
		{
			min = ptr->content;
			id = ptr->id;
		}
		ptr = ptr->next;
	}
	return (id);
}

static void	top_min(t_nest *list)
{
	int	size;
	int	id;

	size = stack_size(list->a_stack);
	id = get_min_id(list->a_stack);
	if (id <= size / 2)
	{
		while (id-- > 0)
			ra(list);
	}
	else
	{
		while (id++ < size)
			rra(list);
	}
}

static void	run_alg(t_nest *list, t_ops *ops, t_ops *temp)
{
	update_ids(list->a_stack);
	update_ids(list->b_stack);
	while (list->b_stack)
	{
		find_cheapest(list, ops, temp);
		make_move(list, ops);
		update_ids(list->a_stack);
		update_ids(list->b_stack);
	}
	top_min(list);
}

void	turksort(t_nest *list)
{
	t_ops	*ops;
	t_ops	*temp;

	ops = (t_ops *) malloc(sizeof(t_ops));
	temp = (t_ops *) malloc(sizeof(t_ops));
	if (!ops || !temp)
		exit_turk(list, ops, temp);
	init_max(list, ops, temp);
	run_alg(list, ops, temp);
	free_ops(ops, temp);
}
