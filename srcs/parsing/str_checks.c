/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:01:31 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 14:01:32 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/push_swap.h"

static void	str_check_chars(t_nest *list, const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ' && *str != '-')
			input_error(list);
		else if (*str == '-' && !ft_isdigit(*(str + 1)))
			input_error(list);
		str++;
	}
}

static void	str_check_limits(t_nest *list, const char *str)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
			input_error(list);
		while (*str == '-' || ft_isdigit(*str))
			str++;
	}
}

void	check_str(t_nest *list, const char *str)
{
	str_check_chars(list, str);
	str_check_limits(list, str);
	list->nbrs = str_init_numbers(list, str);
	str_get_numbers(list, str);
}
