/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:19 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:12:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*swap;

	if (!*stack)
		return ;
	swap = *stack;
	*stack = (*stack)->next;
	swap->next = (*stack)->next;
	(*stack)->next = swap;
}

void	swap_bonus_a_and_b(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
