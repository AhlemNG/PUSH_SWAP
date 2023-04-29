/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:55:25 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:55:29 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(int *tab, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 1;
	while (i <= size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	ft_lstsize(t_list **element)
{
	t_list	*parcourir;
	int		i;

	parcourir = *element;
	i = 0;
	while (parcourir)
	{
		parcourir = parcourir->next;
		i++;
	}
	return (i);
}

void	ft_free(t_list *element)
{
	t_list	*temp;

	while (element)
	{
		temp = (element)->next;
		free(element);
		element = temp;
	}
	element = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while ((temp->next) != NULL)
		temp = temp->next;
	temp->next = new;
}
