/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:15 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:16 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static void	cl_check_chars(t_nest *list, int ac, char **av)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			c = av[i][j];
			if (c != '-' && !ft_isdigit(c))
				input_error(list);
			else if (c == '-' && !ft_isdigit(av[i][j + 1]))
				input_error(list);
		}
	}
}

static void	cl_check_limits(t_nest *list, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			input_error(list);
	}
}

void	check_cl(t_nest *list, int ac, char **av)
{
	cl_check_chars(list, ac, av);
	cl_check_limits(list, ac, av);
	list->nbrs = cl_init_numbers(list, ac);
	cl_get_numbers(list, ac, av);
}
