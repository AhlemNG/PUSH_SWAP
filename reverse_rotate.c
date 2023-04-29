/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:59:49 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:56:01 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*newstack;
	int		i;
	int		j;

	i = ft_lstsize(stack);
	newstack = *stack;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
	}
	(*stack)->next = newstack;
	newstack = *stack;
	j = 1;
	while (j < i)
	{
		(*stack) = (*stack)->next;
		j++;
	}
	(*stack)->next = NULL;
	*stack = newstack;
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
