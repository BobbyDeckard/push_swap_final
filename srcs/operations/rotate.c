/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:54:59 by imeulema          #+#    #+#             */
/*   Updated: 2025/01/07 10:06:25 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

// equivalent to add_back then del_first
static void	rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*ptr;

	ptr = *list;
	last = last_node(ptr);
	last->next = ptr;
	*list = ptr->next;
	ptr->next = NULL;
	ptr->previous = last;
}

void	ra(t_nest *list)
{
	ft_printf("ra\n");
	rotate(&(list->a_stack));
}

void	rb(t_nest *list)
{
	ft_printf("rb\n");
	rotate(&(list->b_stack));
}

void	rr(t_nest *list)
{
	ft_printf("rr\n");
	rotate(&(list->a_stack));
	rotate(&(list->b_stack));
}
