/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:38:08 by anouri            #+#    #+#             */
/*   Updated: 2023/05/03 13:38:10 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_cost_and_direction(t_list **stack, int size)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		{
			if ((temp->temp_position <= (size) / 2) || (size % 2 != 0
					&& temp->temp_position == size / 2 + 1))
			{
				temp->cost = (temp->temp_position) - 1;
				temp->shift_direction = 1;
			}
			else
			{
				temp->cost = size + 1 - temp->temp_position;
				temp->shift_direction = -1;
			}
			temp = temp->next;
		}
	}
}

void	calculate_total_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		temp_a = *stack_a;
		while (temp_a->temp_position != temp_b->target_position)
			temp_a = temp_a->next;
		temp_b->total_cost = temp_b->cost + temp_a->cost;
		temp_b = temp_b->next;
	}
}
