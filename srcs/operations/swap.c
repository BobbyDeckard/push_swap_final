/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:29:34 by imeulema          #+#    #+#             */
/*   Updated: 2024/12/12 16:56:09 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static void	swap(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	if (!*list || !(*list)->next)
		return ;
	node1 = *list;
	node2 = node1->next;
	if (node2->next)
	{
		node3 = node2->next;
		node3->previous = node1;
	}
	else
		node3 = NULL;
	*list = node2;
	node1->next = node3;
	node1->previous = node2;
	node2->previous = NULL;
	node2->next = node1;
}

void	sa(t_nest *list)
{
	ft_printf("sa\n");
	swap(&(list->a_stack));
}

void	sb(t_nest *list)
{
	ft_printf("sb\n");
	swap(&(list->b_stack));
}

void	ss(t_nest *list)
{
	ft_printf("ss\n");
	swap(&(list->a_stack));
	swap(&(list->b_stack));
}
