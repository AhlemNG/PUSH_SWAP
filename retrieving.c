/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:10:11 by anouri            #+#    #+#             */
/*   Updated: 2023/04/16 12:10:23 by anouri           ###   ########.fr       */
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


/*
t_list	*ft_checkduplicate(t_list *element)
{
	t_list	*current;

	current = element;
	while (current->next != NULL)
	{
		while (element->next != NULL)
		{
			if (current->nb == element->next->nb)
			{
				write(1, "Error : presence of a duplicate\n", 32);
				exit(EXIT_FAILURE);
			}
			element = element->next;
		}
		current = current->next;
	}
	return (element);
}
*/
t_list	*ft_get_list(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*node;
	int			i;
	int			content;
	int			doublon;

	doublon = 0;
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		doublon = ft_check_doublon(stack_a, content);
		if (doublon)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		node = ft_lstnew(content);
		if (!node)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}
/*
t_list	*convert_and_add(char **argv)
{
	t_list	*tmp;
	t_list	*stack_a;
	int			value;
	int			i;

	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (!stack_a)
			stack_a = ft_lstnew(value);
		else
		{
			tmp = stack_a;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ft_lstnew(value);
		}
		i++;
	}
	ft_checkduplicate(stack_a);
	if (sorted(&stack_a))
	{
		exit(EXIT_FAILURE);
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
*/
/*je ne teste pas si sorted*/
int	main(int ac, char **av)
{
	t_list *stack1;
	t_list *stack2;
	int long_a;

	stack1 = NULL;
	stack2 = NULL;
	if (ac < 2)
		return (0);
	stack1 = ft_get_list(ac, av);
	long_a = ft_lstsize(&stack1);
	indexing(&stack1);
	push_swap(&stack1, &stack2, long_a);
	//print_value(stack1);
	ft_free(stack1);
    ft_free(stack2);
	return (0);
}
