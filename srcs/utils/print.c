/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:03:01 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:03:02 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

void	print_stack(t_stack *stack, int c)
{
	if (c == 'a')
		ft_printf("A stack:\n");
	else if (c == 'b')
		ft_printf("B stack:\n");
	while (stack)
	{
		if (stack->content < 0)
			ft_printf("%d\n", stack->content);
		else
			ft_printf(" %d\n", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_stacks(t_nest *list)
{
	if (list->a_stack)
		print_stack(list->a_stack, 'a');
	if (list->b_stack)
		print_stack(list->b_stack, 'b');
}
