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

// void	swap(t_list **stack, char c, int long_a)
// {
// 	t_list	*swap;

// 	if (sorted(stack) && ft_lstsize(stack) == long_a)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	if (ft_lstsize(stack) >= 2)
// 	{
// 		swap = *stack;
// 		*stack = (*stack)->next;
// 		swap->next = (*stack)->next;
// 		(*stack)->next = swap;
// 	}
// 	if (c == 'a')
// 		write(1, "sa\n", 3);
// 	if (c == 'b')
// 		write(1, "sb\n", 3);
// }

// void	push(t_list **stack1, t_list **stack2, char c, int long_a)
// {
// 	t_list	*tmp;

// 	if (sorted(stack1) && ft_lstsize(stack1) == long_a)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	if (ft_lstsize(stack1) >= 1)
// 	{
// 		tmp = *stack1;
// 		*stack1 = (*stack1)->next;
// 		tmp->next = *stack2;
// 		*stack2 = tmp;
// 		if (c == 'a')
// 			write(1, "pa\n", 3);
// 		if (c == 'b')
// 			write(1, "pb\n", 3);
// 	}
// }

// void	rotate(t_list **stack_a, char c, int long_a)
// {
// 	t_list	*first_node;

// 	if (sorted(stack_a) && ft_lstsize((stack_a)) == long_a && c == 'a')
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	first_node = (*stack_a);
// 	while ((*stack_a)->next)
// 	{
// 		(*stack_a) = (*stack_a)->next;
// 	}
// 	(*stack_a)->next = first_node;
// 	first_node = first_node->next;
// 	(*stack_a)->next->next = NULL;
// 	if (c == 'a')
// 		write(1, "ra\n", 3);
// 	if (c == 'b')
// 		write(1, "rb\n", 3);
// 	(*stack_a) = first_node;
// }

// void	rr(t_list **stack, char c, int long_a)
// {
// 	t_list	*newstack;
// 	int		i;
// 	int		j;

// 	if (sorted(stack) && ft_lstsize(stack) == long_a && c == 'a')
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	i = ft_lstsize(stack);
// 	newstack = *stack;
// 	while ((*stack)->next != NULL)
// 	{
// 		(*stack) = (*stack)->next;
// 	}
// 	(*stack)->next = newstack;
// 	newstack = *stack;
// 	j = 1;
// 	while (j < i)
// 	{
// 		(*stack) = (*stack)->next;
// 		j++;
// 	}
// 	(*stack)->next = NULL;
// 	*stack = newstack;
// 	if (c == 'a')
// 		write(1, "rra\n", 4);
// 	if (c == 'b')
// 		write(1, "rrb\n", 4);
// }

void	make_shifts_in_a(t_list **stack_a, int position_in_a, int long_a, int sizeA)
{
	if (position_in_a > sizeA / 2)
	{
		position_in_a = sizeA - position_in_a + 1;
		while (position_in_a)
		{
			reverse_rotate_a(stack_a);
			position_in_a--;
		}
	}
	else if (position_in_a <= sizeA / 2)
	{
		while (position_in_a > 1)
		{
			rotate_a(stack_a);
			position_in_a--;
		}
	}
}

void	make_shifts_in_b(t_list **stack_b, int position_in_b, int long_a, int sizeB)
{
	if (position_in_b > sizeB / 2)
	{
		position_in_b = sizeB - position_in_b + 1;
		while (position_in_b >= 1)
		{
			reverse_rotate_b(stack_b);
			position_in_b--;
		}
	}
	else if (position_in_b <= sizeB / 2)
	{
		while (position_in_b > 1)
		{
			rotate_b(stack_b);
			position_in_b--;
		}
	}
}


void	make_rrr(t_list **stack_a, t_list **stack_b, int position_in_a, int position_in_b)
{
	if (position_in_a >= position_in_b)
	{
		while (position_in_a)
		{
			while (position_in_b >=1)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				position_in_b--;
				position_in_a--;
			}
			reverse_rotate_a(stack_a);
			position_in_a--;
		}
	}

	else if (position_in_b >= position_in_a)
	{
		while (position_in_b)
		{
			while (position_in_a)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				position_in_a--;
				position_in_b--;
			}
			reverse_rotate_b(stack_b);
			position_in_b--;
		}
	}
}


void	make_shifts(t_list **stack_a, t_list **stack_b, int long_a)
{
	int position_in_b;
	int position_in_a;
	int sizeB;
	int sizeA;
	t_list *temp;

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
		if(position_in_a > sizeA / 2 && position_in_b > sizeB / 2)
		{
			position_in_a = sizeA - position_in_a + 1;
			position_in_b = sizeB - position_in_b + 1;
			make_rrr(stack_a, stack_b, position_in_a, position_in_b);
		}
		/**********************************************/
		if(position_in_a < sizeA / 2 && position_in_b < sizeB / 2)
		{
			if (position_in_a >= position_in_b)
			{
				while (position_in_a > 1)
				{
					while (position_in_b >=1)
					{
						rotate_a_and_b(stack_a, stack_b);
						position_in_b--;
						position_in_a--;
					}
					rotate_a(stack_a);
					position_in_a--;
				}
			}
			else if (position_in_b >= position_in_a)
			{
				while (position_in_b > 1)
				{
					while (position_in_a)
					{
						rotate_a_and_b(stack_a, stack_b);
						position_in_a--;
						position_in_b--;
					}
					rotate_b(stack_b);
					position_in_b--;
				}
			}
		}
		
		/********************************************/
		else
		{
			make_shifts_in_a(stack_a, position_in_a, long_a, sizeA);
			make_shifts_in_b(stack_b, position_in_b, long_a, sizeB);
		}
		/*******************************************/
		push_a(stack_b, stack_a);
	}
	temp = *stack_a;
	while (temp->final_position != long_a)
		temp = temp->next;
	while (temp->next)
		reverse_rotate_a(stack_a);
}
