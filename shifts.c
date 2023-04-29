/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:57:10 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:57:14 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(int position, int size, int *direction)
{
	int	res;

	res = 0;
	if (position <= (size) / 2)
		res = position - 1;
	else
	{
		res = size + 1 - position;
		*direction = -1;
	}
	return (res);
}

void	make_shifts(t_list **stack_a, t_list **stack_b, int long_a)
{
	int		position_in_b;
	int		position_in_a;
	int		sizeB;
	int		sizeA;
	int		direction_in_a;
	int		direction_in_b;
	t_list	*temp;
	int		cost_in_a;
	int		cost_in_b;

	while (*stack_b)
	{
		direction_in_a = 1;
		direction_in_b = 1;
		temp = *stack_b;
		sizeA = ft_lstsize(stack_a);
		sizeB = ft_lstsize(stack_b);

		temporary_indexing(stack_a);
		temporary_indexing(stack_b);

		position_in_b = find_position_in_b(stack_a, stack_b, sizeA, sizeB);
		while (temp->temp_position != position_in_b)
			temp = temp->next;
		position_in_a = find_position_in_a(*stack_a, temp);
		
		cost_in_a = cost(position_in_a, sizeA, &direction_in_a);
		cost_in_b = cost(position_in_b, sizeB, &direction_in_b);

		if (direction_in_a == 1 && direction_in_b == 1)
			make_rr(stack_a, stack_b, &cost_in_a, &cost_in_b);
		else if (direction_in_a == -1 && direction_in_b == -1)
			make_rrr(stack_a, stack_b, &cost_in_a, &cost_in_b);
		make_shifts_in_a(stack_a, &cost_in_a, direction_in_a);
		make_shifts_in_b(stack_b, &cost_in_b, direction_in_b);
		push_a(stack_b, stack_a);
	}
	final_sort(stack_a, long_a);
}

void final_sort(t_list **stack, int long_a)
{
	t_list	*temp;

	temp = *stack;
	while (temp->final_position != long_a)
		temp = temp->next;
	while (temp->next)
		reverse_rotate_a(stack);
}

// void real_sort(t_list **stack_a, t_list **stack_b, int position_in_a, int position_in_b)
// {
// 	int		direction_in_a;
// 	int		direction_in_b;
// 	int		cost_in_a;
// 	int		cost_in_b;

// 	cost_in_a = cost(position_in_a, sizeA, &direction_in_a);
// 	cost_in_b = cost(position_in_b, sizeB, &direction_in_b);
// }