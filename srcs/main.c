/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:00:37 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:00:42 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static t_nest	*init_list(void)
{
	t_nest	*list;

	list = (t_nest *) malloc(sizeof(t_nest));
	if (!list)
		exit(1);
	list->a_stack = NULL;
	list->b_stack = NULL;
	list->nbrs = NULL;
	return (list);
}

void	push_all_b_but_2(t_nest *list)
{
	int	i;

	i = 0;
	while (i++ + 2 < list->size)
		pb(list);
}

// command to generate random numbers as params:
// ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG
int	main(int ac, char **av)
{
	t_nest	*list;

	if (ac == 1)
		return (0);
	list = init_list();
	parse(list, ac, av);
	sort(list);
	free_all(list);
	return (0);
}
