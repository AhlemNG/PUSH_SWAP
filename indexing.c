/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:57:26 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:57:28 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temporary_indexing(t_list **stack)
{
	t_list	*parcourir;
	int		i;

	i = 1;
	parcourir = *stack;
	while (parcourir)
	{
		parcourir->temp_position = i;
		i++;
		parcourir = parcourir->next;
	}
}

static void	initilize_index(t_list **stack)
{
	t_list	*parcourir;

	parcourir = *stack;
	while (parcourir)
	{
		parcourir->final_position = 0;
		parcourir = parcourir->next;
	}
}

static int	did_not_finish_indexing(t_list **stack)
{
	t_list	*parcourir;

	parcourir = *stack;
	while (parcourir)
	{
		if (parcourir->final_position == 0)
			return (1);
		parcourir = parcourir->next;
	}
	return (0);
}

static void	index_stack(t_list **stack)
{
	t_list	*parcourir;
	long	min;
	int		fp;

	fp = 0;
	while (did_not_finish_indexing(stack))
	{
		parcourir = *stack;
		min = 2147483649;
		while (parcourir)
		{
			if (parcourir->nb < min && parcourir->final_position == 0)
				min = parcourir->nb;
			parcourir = parcourir->next;
		}
		give_final_position(stack, &fp, &min);
	}
}

void	indexing(t_list **stack_a)
{
	initilize_index(stack_a);
	index_stack(stack_a);
}
