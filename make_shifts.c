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

void	make_shifts_in_a(t_list **stack_a, t_list **temp_a)
{
	if (((*temp_a)->shift_direction) == 1)
	{
		while ((*temp_a)->cost > 0)
		{
			rotate_a(stack_a);
			(*temp_a)->cost--;
		}
	}
	else if (((*temp_a)->shift_direction) == -1)
	{
		while ((*temp_a)->cost > 0)
		{
			reverse_rotate_a(stack_a);
			(*temp_a)->cost--;
		}
	}
}

void	make_shifts_in_b(t_list **stack_b, t_list **temp_b)
{
	if ((*temp_b)->shift_direction == 1)
	{
		while ((*temp_b)->cost > 0)
		{
			rotate_b(stack_b);
			(*temp_b)->cost--;
		}
	}
	else if ((*temp_b)->shift_direction == -1)
	{
		while ((*temp_b)->cost > 0)
		{
			reverse_rotate_b(stack_b);
			(*temp_b)->cost--;
		}
	}
}

void	make_rr(t_list **stack_a, t_list **stack_b, t_list **temp_a,
		t_list **temp_b)
{
	while ((*temp_a)->cost > 0 && (*temp_b)->cost > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*temp_a)->cost--;
		(*temp_b)->cost--;
	}
}

void	make_rrr(t_list **stack_a, t_list **stack_b, t_list **temp_a,
		t_list **temp_b)
{
	while ((*temp_a)->cost > 0 && (*temp_b)->cost > 0)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
		(*temp_a)->cost--;
		(*temp_b)->cost--;
	}
}

void	make_shifts(t_list **stack_a, t_list **stack_b, int cheapest_position)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b->temp_position != cheapest_position)
		temp_b = temp_b->next;
	while (temp_a)
	{
		if (temp_a->temp_position == temp_b->target_position)
			break ;
		temp_a = temp_a->next;
	}
	if (temp_a->shift_direction == 1 && temp_b->shift_direction == 1)
		make_rr(stack_a, stack_b, &(temp_a), &(temp_b));
	else if (temp_a->shift_direction == -1 && temp_b->shift_direction == -1)
		make_rrr(stack_a, stack_b, &(temp_a), &(temp_b));
	make_shifts_in_a(stack_a, &(temp_a));
	make_shifts_in_b(stack_b, &(temp_b));
	push_a(stack_b, stack_a);
}
