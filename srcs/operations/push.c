/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:54 by imeulema          #+#    #+#             */
/*   Updated: 2025/01/08 16:26:52 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

// equivalent to add_front then del_first
static void	push(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	a_ptr = *a_stack;
	b_ptr = *b_stack;
	if (a_ptr)
		a_ptr->previous = b_ptr;
	if (b_ptr && b_ptr->next)
	{
		(b_ptr->next)->previous = NULL;
		*b_stack = b_ptr->next;
	}
	else
		*b_stack = NULL;
	b_ptr->next = a_ptr;
	*a_stack = b_ptr;
}

void	pa(t_nest *list)
{
	ft_printf("pa\n");
	push(&(list->a_stack), &(list->b_stack));
}

void	pb(t_nest *list)
{
	ft_printf("pb\n");
	push(&(list->b_stack), &(list->a_stack));
}
