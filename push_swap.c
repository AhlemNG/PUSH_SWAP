#include "push_swap.h"

void    sort_two_numbers(t_list **stack, int long_a)
{
    if((*stack)->nb > (*stack)->next->nb)
        swap_a(stack);
}

t_list  *threenumbers(t_list *stack1, int long_a)
{
    if((stack1->nb < stack1->next->nb) && (stack1->nb > stack1->next->next->nb) && (stack1->next->nb > stack1->next->next->nb))
        reverse_rotate_a(&stack1);
    else if ((stack1->nb < stack1->next->nb) && (stack1->nb < stack1->next->next->nb) && (stack1->next->nb > stack1->next->next->nb))
    {    
        reverse_rotate_a(&stack1);
        swap_a(&stack1);
    }
    else if ((stack1->nb > stack1->next->nb) && (stack1->nb < stack1->next->next->nb) && (stack1->next->nb < stack1->next->next->nb))
      swap_a(&stack1);
    else if ((stack1->nb > stack1->next->nb) && (stack1->nb > stack1->next->next->nb) && (stack1->next->nb < stack1->next->next->nb))
        rotate_a(&stack1);
    else if ((stack1->nb > stack1->next->nb) && (stack1->nb > stack1->next->next->nb) && (stack1->next->nb > stack1->next->next->nb))
    {
         swap_a(&stack1);
        reverse_rotate_a(&stack1);
    }
    return(stack1);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int long_a)
{
	if (long_a == 2)
		sort_two_numbers(stack_a, long_a);
	else
	{
		presort(stack_a, stack_b, long_a);
		make_shifts(stack_a, stack_b, long_a);
	}
}
