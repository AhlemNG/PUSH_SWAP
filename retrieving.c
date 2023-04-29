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
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->nb = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_get_list(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*node;
	int			i;
	long long	content;
	int			doublon;

	doublon = 0;
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		if (content < INT_MIN || content > INT_MAX)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		doublon = ft_check_doublon(stack_a, content);
		if (doublon)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		node = ft_lstnew((int)content);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

void	print_value(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("[%d] [%d] {%d} \n", lst->temp_position, lst->final_position,
				lst->nb);
		lst = lst->next;
	}
}

/*je ne teste pas si sorted*/
int	main(int ac, char **av)
{
	t_list	*stack1;
	t_list	*stack2;
	int		long_a;

	/* checks to do before initializing stacks */
	if (ac > 2)
	{
		// if (!is_valid_argument(argv))
		// {
		// write(1,"Error\n", 7);
		// exit(EXIT_FAILURE);
		// }
		stack2 = NULL;
		stack1 = ft_get_list(ac, av);
		if (sorted(&stack1))
			return (0);
		long_a = ft_lstsize(&stack1);
		indexing(&stack1); /*done*/
		push_swap(&stack1, &stack2, long_a);
		// print_value(stack1);
		ft_free(stack1);
		ft_free(stack2);
	}
	return (0);
}
