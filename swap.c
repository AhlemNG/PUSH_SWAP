/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:19:57 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:58:03 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*swap;

	swap = *stack;
	*stack = (*stack)->next;
	swap->next = (*stack)->next;
	(*stack)->next = swap;
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}
