/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:34:27 by anouri            #+#    #+#             */
/*   Updated: 2023/05/03 13:34:29 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, int long_a)
{
	if (long_a == 2)
		sort_two_numbers(stack_a, long_a);
	else
	{
		indexing(stack_a);
		presort(stack_a, stack_b, long_a);
		main_sort(stack_a, stack_b, long_a);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		long_a;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = get_list(ac, av);
		if (sorted(&stack_a))
			return (0);
		long_a = ft_lstsize(&stack_a);
		push_swap(&stack_a, &stack_b, long_a);
	}
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
