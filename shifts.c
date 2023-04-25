#include "push_swap.h"

int	cost(int position, int size, int *direction)
{
    int res;

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

void	make_shifts_in_a(t_list **stack_a, int *cost_in_a, int direction)
{
    if ((direction) == 1)
	{
		while ((*cost_in_a) > 0)
		{
			rotate_a(stack_a);
			(*cost_in_a)--;
		}
	}
    else if (direction == -1)
	{
		while ((*cost_in_a) > 0)
		{
			reverse_rotate_a(stack_a);
			(*cost_in_a)--;
		}
	}
}

void	make_shifts_in_b(t_list **stack_b, int *cost_in_b, int direction)
{
    if ((direction) == 1)
	{
		while ((*cost_in_b) > 0)
		{
			rotate_b(stack_b);
			(*cost_in_b)--;
		}
	}
    else if (direction == -1)
	{
		while ((*cost_in_b) > 0)
		{
			reverse_rotate_b(stack_b);
			(*cost_in_b)--;
		}
	}
}

void	make_rr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b)
{
	while ((*cost_in_a) > 0 && (*cost_in_b) > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)--;
		(*cost_in_b)--;
	}
}

void	make_rrr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b)
{
	while ((*cost_in_a) > 0 && (*cost_in_b) > 0)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
		(*cost_in_a)--;
		(*cost_in_b)--;
	}
}

void	make_shifts(t_list **stack_a, t_list **stack_b, int long_a)
{
    int position_in_b;
	int position_in_a;
	int sizeB;
	int sizeA;
	int	direction_in_a;
	int	direction_in_b;
	t_list *temp;
	int	cost_in_a;
	int	cost_in_b;

	while (*stack_b)
	{
		
		direction_in_a = 1;
		direction_in_b = 1;
		temp = *stack_b;
		sizeA = ft_lstsize(stack_a);
		sizeB = ft_lstsize(stack_b);
		temporary_indexing(stack_a);	
		temporary_indexing(stack_b);
		// printf("stack_a:\n");
		// print_value(*stack_a);
		// printf("stack_b:\n");
		// print_value(*stack_b);
		/************************************************************/
		position_in_b = shift_count(stack_a, stack_b, sizeA, sizeB);
		while (temp->temp_position != position_in_b)
			temp = temp->next;
		position_in_a = find_position_in_a(*stack_a, temp);
		// printf("position_a = %d\n", position_in_a);
		// printf("position_b = %d\n", position_in_b);
        /************************************************************/
		cost_in_a = cost(position_in_a, sizeA, &direction_in_a);
		// printf("cost_a = %d\n", cost_in_a);
        cost_in_b = cost(position_in_b, sizeB, &direction_in_b);
		// printf("cost_b = %d\n", cost_in_b);
			// printf("				directiondans a = %d\n", direction_in_a);
			// printf("				directiondans b = %d\n", direction_in_b);
		/**********************************************************/
        if (direction_in_a == 1 && direction_in_b == 1)
            make_rr(stack_a, stack_b, &cost_in_a, &cost_in_b);
        // /**********************************************************/
		// else 
		if (direction_in_a == -1 && direction_in_b == -1)
            make_rrr(stack_a, stack_b, &cost_in_a, &cost_in_b);
		// /*********************************************************/
   		// //else

		// printf("cost_a = %d\n", cost_in_a);

		// printf("cost_b = %d\n", cost_in_b);
		
		{
			make_shifts_in_a(stack_a, &cost_in_a, direction_in_a);
			make_shifts_in_b(stack_b, &cost_in_b, direction_in_b);
		}
		/********************************************************/
		push_a(stack_b, stack_a);
	}
	temp = *stack_a;
	while (temp->final_position != long_a)
		temp = temp->next;
	while (temp->next)
		reverse_rotate_a(stack_a);
}
