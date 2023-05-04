/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:24 by anouri            #+#    #+#             */
/*   Updated: 2023/05/03 13:35:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_a(t_list *stack_a, t_list *node)
{
	int		pos;
	t_list	*stk;

	pos = INT_MAX;
	stk = stack_a;
	while (stack_a)
	{
		if (stack_a->final_position > node->final_position
			&& stack_a->final_position < pos)
			pos = stack_a->final_position;
		stack_a = stack_a->next;
	}
	while (stk->final_position != pos)
		stk = stk->next;
	return (stk->temp_position);
}

void	assign_target_position(t_list *stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	while (temp)
	{
		temp->target_position = find_position_in_a(stack_a, temp);
		temp = temp->next;
	}
}

int	get_min_cost(t_list *stack_b)
{
	int	min;

	min = INT_MAX;
	while (stack_b)
	{
		if (min > stack_b->total_cost)
			min = stack_b->total_cost;
		stack_b = stack_b->next;
	}
	return (min);
}

int	get_cheapest_position(t_list *stack_b)
{
	int	min;

	min = get_min_cost(stack_b);
	while (stack_b->total_cost != min)
	{
		stack_b = stack_b->next;
	}
	return (stack_b->temp_position);
}

void	give_final_position(t_list **stack, int *fp, long *min)
{
	t_list	*parcourir;

	parcourir = *stack;
	while (parcourir)
	{
		if (parcourir->nb == *min)
		{
			(*fp)++;
			parcourir->final_position = *fp;
		}
		parcourir = parcourir->next;
	}
}
