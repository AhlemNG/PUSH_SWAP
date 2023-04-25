#include "push_swap.h"

void	presort(t_list **stack_a, t_list **stack_b, int long_a)
{
	int	mediane;

	mediane = 0;
	indexing(stack_a);
	mediane = (ft_lstsize(stack_a) - 3) / 2;
	//printf("mediane = %d\n", mediane);
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
	*stack_a = threenumbers(*stack_a, long_a);
}
