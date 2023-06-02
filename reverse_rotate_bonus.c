/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:10:02 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:11:12 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*newstack;
	int		i;
	int		j;

	if (!*stack)
		return ;
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

void	reverse_rotate_bonus_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
