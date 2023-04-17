/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:56:32 by anouri            #+#    #+#             */
/*   Updated: 2023/04/16 13:07:08 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_list **SRC, t_list **DST)
{
	t_list	*tmp;

	tmp = *SRC;
	*SRC = (*SRC)->next;
	tmp->next = *DST;
	*DST = tmp;
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
