/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:02:29 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:02:36 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			j;
	long long	nb;

	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	j = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j++;
		i++;
	}
	nb = 0;
	while (is_digit(nptr[i]))
	{
		nb = (nptr[i] - 48) + (nb * 10);
		i++;
	}
	if (j % 2 != 0)
		nb = -nb;
	return (nb);
}

int	no_doublon(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str_nb_compare(str[i], str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	j;

	j = 0;
	if (!str)
		return (0);
	if ((str[j] == '-' || str[j] == '+') && str[j + 1] != '\0')
		j++;
	while (str[j] != '\0' && is_digit(str[j]) == 1)
		j++;
	if (str[j] != '\0' && is_digit(str[j]) == 0)
		return (0);
	return (1);
}

int	check_if_valid(char **argv)
{
	long long	content;
	int			i;

	i = 1;
	if (no_doublon(argv) == 0)
		return (0);
	while (argv[i])
	{
		if (is_number(argv[i]) == 0)
			return (0);
		content = ft_atoi(argv[i]);
		if ((content < INT_MIN || content > INT_MAX))
			return (0);
		i++;
	}
	return (1);
}
