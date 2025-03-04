/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:56 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:57 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

int	check_order(t_stack *stack)
{
	t_stack	*ptr;

	if (!stack)
		return (0);
	ptr = stack;
	while (ptr)
	{
		if (ptr->next && ptr->next->content < ptr->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	sort2(t_nest *list)
{
	t_stack	*stack;

	stack = list->a_stack;
	if (stack->next->content < stack->content)
		sa(list);
}

void	sort3(t_nest *list)
{
	t_stack	n1;
	t_stack	n2;
	t_stack	n3;

	n1 = *(list->a_stack);
	n2 = *n1.next;
	n3 = *n2.next;
	if (n2.content > n3.content && n3.content > n1.content)
	{
		sa(list);
		ra(list);
	}
	else if (n3.content > n1.content && n1.content > n2.content)
		sa(list);
	else if (n2.content > n1.content && n1.content > n3.content)
		rra(list);
	else if (n1.content > n3.content && n3.content > n2.content)
		ra(list);
	else if (n1.content > n2.content && n2.content > n3.content)
	{
		sa(list);
		rra(list);
	}
}

void	sort4(t_nest *list)
{
	init_id4(list->a_stack);
	move_smallest(list);
	sort3(list);
	pa(list);
}

void	sort(t_nest *list)
{
	int	size;

	size = list->size;
	if (check_order(list->a_stack))
		return ;
	if (size == 2)
		sort2(list);
	else if (size == 3)
		sort3(list);
	else if (size == 4)
		sort4(list);
	else if (size == 5)
		sort5(list);
	else
		turbosort(list);
}
