/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:36:51 by anouri            #+#    #+#             */
/*   Updated: 2023/05/03 13:36:54 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort two numbers*/
void	sort_two_numbers(t_list **stack, int long_a)
{
	if ((*stack)->nb > (*stack)->next->nb)
		swap_a(stack);
}

/*sort three numbers*/
void	sort_three_numbers(t_list **s, int long_a)
{
	if (((*s)->nb < (*s)->next->nb) && ((*s)->nb > (*s)->next->next->nb)
		&& ((*s)->next->nb > ((*s)->next->next)->nb))
		reverse_rotate_a(s);
	else if (((*s)->nb < (*s)->next->nb) && ((*s)->nb < (*s)->next->next->nb)
		&& ((*s)->next->nb > (*s)->next->next->nb))
	{
		reverse_rotate_a(s);
		swap_a(s);
	}
	else if (((*s)->nb > (*s)->next->nb) && ((*s)->nb < (*s)->next->next->nb)
		&& ((*s)->next->nb < (*s)->next->next->nb))
		swap_a(s);
	else if (((*s)->nb > (*s)->next->nb) && ((*s)->nb > (*s)->next->next->nb)
		&& ((*s)->next->nb < (*s)->next->next->nb))
		rotate_a(s);
	else if (((*s)->nb > (*s)->next->nb) && ((*s)->nb > (*s)->next->next->nb)
		&& ((*s)->next->nb > (*s)->next->next->nb))
	{
		swap_a(s);
		reverse_rotate_a(s);
	}
}

/*sort*/
void	presort(t_list **stack_a, t_list **stack_b, int long_a)
{
	int	mediane;

	mediane = 0;
	indexing(stack_a);
	mediane = (ft_lstsize(stack_a) - 3) / 2;
	while (ft_lstsize(stack_a) > 3)
	{
		while (((*stack_a)->final_position == long_a
				|| (*stack_a)->final_position == long_a - 1
				|| (*stack_a)->final_position == long_a - 2))
		{
			rotate_a(stack_a);
		}
		if ((*stack_a)->final_position < mediane)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else if ((*stack_a)->final_position >= mediane)
			push_b(stack_a, stack_b);
	}
	sort_three_numbers(stack_a, long_a);
}

void	main_sort(t_list **stack_a, t_list **stack_b, int long_a)
{
	int	size_a;
	int	size_b;
	int	cheapest_position;

	while (*stack_b)
	{
		size_a = ft_lstsize(stack_a);
		size_b = ft_lstsize(stack_b);
		temporary_indexing(stack_a);
		temporary_indexing(stack_b);
		assign_target_position(*stack_a, stack_b);
		assign_cost_and_direction(stack_a, size_a);
		assign_cost_and_direction(stack_b, size_b);
		calculate_total_cost(stack_a, stack_b);
		cheapest_position = get_cheapest_position(*stack_b);
		make_shifts(stack_a, stack_b, cheapest_position);
	}
	final_sort(stack_a, long_a);
}

void	final_sort(t_list **stack, int long_a)
{
	t_list	*temp;

	temp = *stack;
	while (temp->final_position != long_a)
		temp = temp->next;
	while (temp->next)
		reverse_rotate_a(stack);
}
