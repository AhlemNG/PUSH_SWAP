/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:03:44 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:03:48 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	is_a_zero(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static void	skip_sign_and_zeros(const char *s1, const char *s2, int *count1,
		int *count2)
{
	if (s1[*count1] == '+' && s2[*count2] != '+')
		(*count1)++;
	else if (s1[*count1] != '+' && s2[*count2] == '+')
		(*count2)++;
	else if (s1[*count1] == '-' && s2[*count2] == '-')
	{
		(*count1)++;
		(*count2)++;
	}
	while ((s1[*count1] == '0' && s2[*count2] == '0'))
	{
		(*count1)++;
		(*count2)++;
	}
	while ((s1[*count1] == '0' && s2[*count2] != '0'))
		(*count1)++;
	while ((s1[*count1] != '0' && s2[*count2] == '0'))
		(*count2)++;
}

int	str_nb_compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	if (is_a_zero(s1) && is_a_zero(s2))
		return (0);
	i = 0;
	j = 0;
	skip_sign_and_zeros(s1, s2, &i, &j);
	while (s1[i] != '\0' && s2[j] != '\0' && (s1[i] == s2[j]))
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
