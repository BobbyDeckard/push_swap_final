/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:22 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:23 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

// check_max() and check_min() work almost exactly the same.
// They compare the given content to the current min or max
// value inside the A stack.
// Iterates through the A stack, comparing its values to a temp
// variable stocking the max or min value currently encountered.
// Once the whole stack has been iterated through, compares the
// retrieve max or min value to the value of the current number
// being examined.
// The only difference between check_mac and check_min being that
// it returns the exact id of the min value but the id of the
// max value is incremented by one to place the new max after it.
int	check_max(t_stack *stack, int content)
{
	t_stack	*ptr;
	int		max;
	int		id;

	ptr = stack;
	max = INT_MIN;
	while (ptr)
	{
		if (max < ptr->content)
		{
			max = ptr->content;
			id = ptr->id;
		}
		ptr = ptr->next;
	}
	if (content > max)
		return (id + 1);
	return (-1);
}

int	check_min(t_stack *stack, int content)
{
	t_stack	*ptr;
	int		min;
	int		id;

	ptr = stack;
	min = INT_MAX;
	while (ptr)
	{
		if (min > ptr->content)
		{
			min = ptr->content;
			id = ptr->id;
		}
		ptr = ptr->next;
	}
	if (content < min)
		return (id);
	return (-1);
}

int	better_combo(t_ops *ops, t_ops *temp)
{
	int	old_combo;
	int	new_combo;

	old_combo = 0;
	new_combo = 0;
	if ((ops->a_ops < 0) == (ops->b_ops < 0))
		old_combo = ft_abs(ft_abs(ops->a_ops) - ft_abs(ops->b_ops));
	if ((temp->a_ops < 0) == (temp->b_ops < 0))
		new_combo = ft_abs(ft_abs(temp->a_ops) - ft_abs(temp->b_ops));
	if (new_combo > old_combo)
		return (1);
	return (0);
}

// Is called after a new current min or max value is found for the A stack, or
// to finalize the find_place() function.
// check_min() and check_max() virtually serve the same role as find_place(),
// but with dedicated methods to determine the future id of our number.
// Works just the same as move_to_push()
int	place(t_ops *ops, int id)
{
	if (id <= ops->a_half)
		ops->a_ops = id;
	else
		ops->a_ops = id - ops->a_size;
	return (ft_abs(ops->a_ops));
}

// Is called when the current value being examined does not qualify as a new min
// or max for the other stack, allowing for comparison with the already sorted
// A stack.
// Iterates through the A stack and compares the current value with a pair of
// values in the A stack. If the current value is bigger than the previous and
// smaller than the next, its right position is between the two, meaning its
// current correct id is the id of our second number.
// This id is then given to the place() function as the destination of our
// number.
int	find_place(t_stack *stack, t_ops *ops, int content)
{
	t_stack	*ptr;
	t_stack	*next;
	int		id;

	ptr = stack;
	id = 0;
	while (ptr)
	{
		next = ptr->next;
		if (next && content > ptr->content && content < next->content)
			id = next->id;
		ptr = ptr->next;
	}
	return (place(ops, id));
}
