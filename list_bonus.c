/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:00:52 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:00:54 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
