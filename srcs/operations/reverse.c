/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:56:11 by imeulema          #+#    #+#             */
/*   Updated: 2025/01/07 10:06:22 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

// equivalent to add_front then del_last
static void	reverse_rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*ptr;

	ptr = *list;
	last = last_node(ptr);
	ptr->previous = last;
	last->next = ptr;
	(last->previous)->next = NULL;
	last->previous = NULL;
	*list = last;
}

void	rra(t_nest *list)
{
	ft_printf("rra\n");
	reverse_rotate(&(list->a_stack));
}

void	rrb(t_nest *list)
{
	ft_printf("rrb\n");
	reverse_rotate(&(list->b_stack));
}

void	rrr(t_nest *list)
{
	ft_printf("rrr\n");
	reverse_rotate(&(list->a_stack));
	reverse_rotate(&(list->b_stack));
}
