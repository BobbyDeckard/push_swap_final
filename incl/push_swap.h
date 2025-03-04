/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:52:33 by imeulema          #+#    #+#             */
/*   Updated: 2025/01/13 16:35:46 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include "../libft/libft.h"

// MACROS
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

// STRUCTS
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				content;
	int				pos;
	int				id;
}	t_stack;

typedef struct s_nest
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		*nbrs;
	int		*pos;
	int		size;
}	t_nest;

typedef struct s_ops
{
	int	a_ops;
	int	b_ops;
	int	a_size;
	int	b_size;
	int	a_half;
	int	b_half;
	int	max;
	int	mid;
}	t_ops;

typedef struct s_five
{
	int	smolst;
	int	ops;
}	t_five;

// OPERATIONS
void	pa(t_nest *list);
void	pb(t_nest *list);
void	ra(t_nest *list);
void	rb(t_nest *list);
void	rr(t_nest *list);
void	rra(t_nest *list);
void	rrb(t_nest *list);
void	rrr(t_nest *list);
void	sa(t_nest *list);
void	sb(t_nest *list);
void	ss(t_nest *list);

//PARSING
void	check_args(t_nest *list, int ac, char **av);
void	check_cl(t_nest *list, int ac, char **av);
void	check_duplicateS(t_nest *list);
void	check_str(t_nest *list, const char *str);
void	cl_get_numbers(t_nest *list, int ac, char **av);
void	input_error(t_nest *list);
void	parse(t_nest *list, int ac, char **av);
void	str_get_numbers(t_nest *list, const char *str);
int		*cl_init_numbers(t_nest *list, int ac);
int		*str_init_numbers(t_nest *list, const char *str);

// SORTING
void	exit_turk(t_nest *list, t_ops *ops, t_ops *temp);
void	find_cheapest(t_nest *list, t_ops *ops, t_ops *temp);
void	free_ops(t_ops *ops, t_ops *temp);
void	init_id4(t_stack *stack);
void	init_max(t_nest *list, t_ops *ops, t_ops *temp);
void	make_move(t_nest *list, t_ops *ops);
void	move_a(t_nest *list, t_ops *ops);
void	move_b(t_nest *list, t_ops *ops);
void	move_smallest(t_nest *list);
void	sort(t_nest *list);
void	sort2(t_nest *list);
void	sort3(t_nest *list);
void	sort4(t_nest *list);
void	sort5(t_nest *list);
void	turbosort(t_nest *list);
void	turksort(t_nest *list);
int		*get_positions(t_nest *list);
int		better_combo(t_ops *ops, t_ops *temp);
int		check_max(t_stack *stack, int content);
int		check_min(t_stack *stack, int content);
int		check_order(t_stack *stack);
int		find_place(t_stack *stack, t_ops *ops, int content);
int		place(t_ops *ops, int id);

// UTILS
t_stack	*last_node(t_stack *stack);
t_stack	*new_node(t_nest *list, int id);
void	add_back(t_stack *stack, t_stack *new);
void	exit_all(t_nest *list);
void	free_all(t_nest *list);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack, int c);
void	print_stacks(t_nest *list);
int		stack_size(t_stack *stack);
int		get_content(t_stack *stack, int id);

#endif
