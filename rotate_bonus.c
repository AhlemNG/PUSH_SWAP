/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:11:20 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:11:24 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_list **stack)
{
	t_list	*first_node;

	if (!*stack)
		return ;
	first_node = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = first_node;
	first_node = first_node->next;
	(*stack)->next->next = NULL;
	*stack = first_node;
}

void	rotate_bonus_a_and_b(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
