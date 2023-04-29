/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shifts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:15:24 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 14:15:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_shifts_in_a(t_list **stack_a, int *cost_in_a, int direction)
{
	if ((direction) == 1)
	{
		while ((*cost_in_a) > 0)
		{
			rotate_a(stack_a);
			(*cost_in_a)--;
		}
	}
	else if (direction == -1)
	{
		while ((*cost_in_a) > 0)
		{
			reverse_rotate_a(stack_a);
			(*cost_in_a)--;
		}
	}
}

void	make_shifts_in_b(t_list **stack_b, int *cost_in_b, int direction)
{
	if ((direction) == 1)
	{
		while ((*cost_in_b) > 0)
		{
			rotate_b(stack_b);
			(*cost_in_b)--;
		}
	}
	else if (direction == -1)
	{
		while ((*cost_in_b) > 0)
		{
			reverse_rotate_b(stack_b);
			(*cost_in_b)--;
		}
	}
}

void	make_rr(t_list **stack_a, t_list **stack_b, int *cost_in_a,
		int *cost_in_b)
{
	while ((*cost_in_a) > 0 && (*cost_in_b) > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)--;
		(*cost_in_b)--;
	}
}

void	make_rrr(t_list **stack_a, t_list **stack_b, int *cost_in_a,
		int *cost_in_b)
{
	while ((*cost_in_a) > 0 && (*cost_in_b) > 0)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)--;
		(*cost_in_b)--;
	}
}
