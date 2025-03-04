/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:36 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:37 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static int	count_numbers(const char *str)
{
	int	count;

	count = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == '-')
			str++;
		while (ft_isdigit(*str))
			str++;
		count++;
		while (*str == ' ')
			str++;
	}
	return (count);
}

void	str_get_numbers(t_nest *list, const char *str)
{
	int	*nbrs;
	int	i;

	nbrs = list->nbrs;
	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		nbrs[i++] = ft_atoi(str);
		while (ft_isdigit(*str) || *str == '-')
			str++;
	}
}

int	*str_init_numbers(t_nest *list, const char *str)
{
	int	*numbers;
	int	size;

	size = count_numbers(str);
	list->size = size;
	numbers = (int *) malloc(size * sizeof(int));
	if (!numbers)
		exit_all(list);
	return (numbers);
}
