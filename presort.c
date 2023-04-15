#include "push_swap.h"

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
			rotate(stack_a, 'a', long_a);
		}
		if ((*stack_a)->final_position < mediane)
		{
			push(stack_a, stack_b, 'b', long_a);
			rotate(stack_b, 'b', long_a);
		}
		else if ((*stack_a)->final_position >= mediane)
			push(stack_a, stack_b, 'b', long_a);
	}
	*stack_a = threenumbers(*stack_a, long_a);
}
