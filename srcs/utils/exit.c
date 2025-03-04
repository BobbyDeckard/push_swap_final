/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:52 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:53 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_all(t_nest *list)
{
	if (list)
	{
		if (list->a_stack)
			free_stack(list->a_stack);
		if (list->b_stack)
			free_stack(list->b_stack);
		if (list->nbrs)
			free(list->nbrs);
		if (list->pos)
			free(list->pos);
	}
	free(list);
}

void	exit_all(t_nest *list)
{
	free_all(list);
	exit(1);
}
