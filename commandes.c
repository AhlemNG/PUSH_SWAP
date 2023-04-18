/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:08:56 by anouri            #+#    #+#             */
/*   Updated: 2023/04/16 13:03:13 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(int position, int size)
{
    int res;

    res = 0;
    if (position <= (size) / 2)
        res = position - 1;
    else
        res = -(size + 1 - position);
    return (res);
}
void	make_shifts_in_a(t_list **stack_a, int *cost_in_a)
{
	if ((*cost_in_a < 0))
	{
		while ((*cost_in_a < 0))
		{
			reverse_rotate_b(stack_a);
			(*cost_in_a)++;
		}
	}
	if ((*cost_in_a > 0))
	{
		while ((*cost_in_a > 0))
		{
			rotate_b(stack_a);
			(*cost_in_a)--;
		}
	}
}

void	make_shifts_in_b(t_list **stack_b, int *cost_in_b)
{
	if ((*cost_in_b < 0))
	{
		while ((*cost_in_b < 0))
		{
			reverse_rotate_b(stack_b);
			(*cost_in_b)++;
		}
	}
	if ((*cost_in_b > 0))
	{
		while ((*cost_in_b > 0))
		{
			rotate_b(stack_b);
			(*cost_in_b)--;
		}
	}
}


void	make_rr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b)
{
	while (*cost_in_a > 0 && cost_in_b > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)--;
		(*cost_in_b)-- ;
	}
}

void	make_rrr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b)
{
	while (*cost_in_a < 0 && cost_in_b < 0)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)++;
		(*cost_in_b)++;
	}
}

void	make_shifts(t_list **stack_a, t_list **stack_b, int long_a)
{
	int position_in_b;
	int position_in_a;
	int sizeB;
	int sizeA;
	t_list *temp;
	int	cost_in_a;
	int	cost_in_b;

	while (*stack_b)
	{
		temp = *stack_b;
		sizeA = ft_lstsize(stack_a);
		sizeB = ft_lstsize(stack_b);
		temporary_indexing(stack_a);	
		temporary_indexing(stack_b);
		position_in_b = shift_count(stack_a, stack_b, sizeA, sizeB);
		while (temp->temp_position != position_in_b)
			temp = temp->next;
		position_in_a = find_position_in_a(*stack_a, temp);
		/**********************************************/
		cost_in_a = cost(position_in_a, sizeA);
		cost_in_b = cost(position_in_b, sizeB);
		/************************************************/
		 if(cost_in_a < 0 && cost_in_b < 0)
		 	make_rrr(stack_a, stack_b, &cost_in_a, &cost_in_b);
		 /**********************************************/
		 else if(cost_in_a > 0 && cost_in_b > 0)
			make_rr(stack_a, stack_b, &cost_in_a, &cost_in_b);
		 /********************************************/
			make_shifts_in_a(stack_a, &cost_in_a);
			make_shifts_in_b(stack_b, &cost_in_b);
		/*******************************************/
		push_a(stack_b, stack_a);
	}
	temp = *stack_a;
	while (temp->final_position != long_a)
		temp = temp->next;
	while (temp->next)
		reverse_rotate_a(stack_a);
}
