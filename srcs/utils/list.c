/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:56 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:57 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	*new_node(t_nest *list, int id)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		exit_all(list);
	new->content = (list->nbrs)[id];
	new->pos = (list->pos)[id];
	new->id = id;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	add_back(t_stack *stack, t_stack *new)
{
	t_stack	*last;

	last = last_node(stack);
	last->next = new;
	new->previous = last;
}

int	stack_size(t_stack *stack)
{
	t_stack	*ptr;
	int		size;

	ptr = stack;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

int	get_content(t_stack *stack, int id)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->id != id)
		ptr = ptr->next;
	return (ptr->content);
}
