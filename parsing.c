/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:54:27 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:54:29 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*conversion en int*/

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

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
	if ((nptr[i] < '0' || nptr[i] > '9'))
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
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

// int	is_valid_argument(int argc, char **argv)
// {
// 	int	i;

// 	i = 1;
// 	while(i <= argc)
// 	{
// 		if (!is_digit(argv[i]))
// 			return (0);
// 		if
// 		i++;
// 	}
// 	return (1);
// }

/*recherche de doublon*/
int	ft_check_doublon(t_list *lst, int content)
{
	while (lst)
	{
		if (lst->nb == content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

/*verification si triee*/

int	sorted(t_list **stack_a)
{
	t_list	*parcourir;

	parcourir = *stack_a;
	while (parcourir->next)
	{
		if (parcourir->nb > parcourir->next->nb)
			return (0);
		parcourir = parcourir->next;
	}
	return (1);
}
