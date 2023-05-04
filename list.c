/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:10:11 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:55:44 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->nb = content;
	new->next = NULL;
	return (new);
}

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

t_list	*get_list(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*node;
	int			i;
	long long	content;
	int			doublon;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (!check_if_valid(argv))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		content = ft_atoi(argv[i]);
		node = ft_lstnew((int)content);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}
