/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:15 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:02:16 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

// Gets the number of moves necessary to push a number
// to the other stack from its current position.
// If the id of the number (which is its current position
// in the stack, with 0 being the top) is smaller or equal
// to the half of the stack size, then the smallest numbers
// of operations needed to rotate it to the top is obtained
// by using regular rotations, and if it is bigger than the
// half size, reverse rotations are the cheaper option.
// The number of rotations necessary is also easily obtained:
// in case of regular rotations, it simply is equal to the
// number's id (to push the number with the id of 1, we need
// to do one regular rotation to bring it to the position 0).
// In case of reverse rotations, we simply need to subtract
// the current size of the stack to the number's id (if our
// stack contains 10 numbers, the last number in the stack
// will have the id of 9 and will be |9 - 10| = 1 move away,
// while the negative sign informs us that we need to use
// reverse rotations).
static int	moves_to_push(t_ops *ops, int id)
{
	if (id <= ops->b_half)
		ops->b_ops = id;
	else
		ops->b_ops = id - ops->b_size;
	return (ft_abs(ops->b_ops));
}

// Calculates the total cost necessary to move a number to its
// place in the A stack.
// Proceeds in 2 steps:
// 1.	Get the number of moves necessary to push our number to 
//	the other stack, see above.
// 2.	If it is currently bigger or smaller than any value in the
//	other stack, will directly call the place() function, if
//	not, find_place() is called, which then calls place() itself.
// The added value retrieved from those functions is then returned.
static int	get_cost(t_nest *list, t_ops *ops, int id)
{
	int	content;
	int	cost;
	int	id_max;
	int	id_min;

	content = get_content(list->b_stack, id);
	cost = moves_to_push(ops, id);
	id_max = check_max(list->a_stack, content);
	id_min = check_min(list->a_stack, content);
	if (id_max >= 0)
		cost += place(ops, id_max);
	else if (id_min >= 0)
		cost += place(ops, id_min);
	else
		cost += find_place(list->a_stack, ops, content);
	return (cost);
}

// Copies the values stored in the temp to the ops that will be used
// to make the move.
static void	save_ops(t_ops *ops, t_ops *temp)
{
	ops->a_ops = temp->a_ops;
	ops->b_ops = temp->b_ops;
}

static void	update_ops(t_nest *list, t_ops *ops, t_ops *temp)
{
	ops->b_size = stack_size(list->b_stack);
	ops->b_half = ops->b_size / 2;
	ops->a_size = stack_size(list->a_stack);
	ops->a_half = ops->a_size / 2;
	temp->b_size = ops->b_size;
	temp->b_half = ops->b_half;
	temp->a_size = ops->a_size;
	temp->a_half = ops->a_half;
}

// Finds the cheapest move to push a number from B to A.
// Is called each time a move is plotted, updating the size of each
// stack every round.
// Iterates through the B stack and retrieves the cost it would take
// to move the id'd node to its right place in the A stack.
// The ops struct contain various informations on the current state of
// the stacks, and most importantly the a_ops and b_ops which are
// further used to make the move.
// a_ops and b_ops are int values that indicate both the distance to
// travel (absolute value) and the direction in which to travel (sign).
// For example, with a_ops = -3 and b_ops = -2, the plotted moves would
// be 3 reverse rotations in the A stack and 2 reverse rotations in the
// B stack (they would be regular rotations with 3 and 2), thus, we can
// combine 2 of the rotations with the rr() operation and then finish
// with ra(), totaling the number of operations needed to 3, which
// represents the cost of the operation.
//
// ERRATUM: we do not count combined operations, we use better_combo()
// to compare results with equal total number of operations, then
// chosing the one with the most combined operations
void	find_cheapest(t_nest *list, t_ops *ops, t_ops *temp)
{
	int	id;
	int	cost;
	int	cheapest;

	id = -1;
	cheapest = INT_MAX;
	update_ops(list, ops, temp);
	while (++id < ops->b_size)
	{
		cost = get_cost(list, temp, id);
		if (cost < cheapest || (cost == cheapest && better_combo(ops, temp)))
		{
			cheapest = cost;
			save_ops(ops, temp);
		}
	}
}
