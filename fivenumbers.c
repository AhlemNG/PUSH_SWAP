/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:53:56 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:54:03 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list   **fivenumbers(t_list  **stack1, t_list   **stack2, int long_a)
// {
//     t_list   *parcourir;
//     push(stack1, stack2, 'b', long_a);
//     push(stack1, stack2, 'b', long_a);
//     *stack1 = threenumbers(*stack1, long_a);
//     if ((*stack2)->nb < (*stack2)->next->nb)
//         (*stack2) = swap(*stack2, 'b', long_a);
//     push(stack2, stack1, 'a', long_a);
   
//     parcourir = (*stack1);
//     if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb > parcourir->next->next->next->nb))
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb < parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//         (*stack1) = swap(*stack1, 'a', long_a);
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     push(stack2, stack1, 'a', long_a);
//     parcourir = (*stack1);
//     if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb > parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb < parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = swap(*stack1, 'a', long_a);
//     }
//     return (stack1);
// }

// t_list   **fivenumbers(t_list  **stack1, t_list   **stack2)
// {
//     t_list   *ma_stack;
//     t_list   *node;
//     int i;

//     ma_stack = NULL;
//     i = 1;
//     while (i < 6)
//     {
//         node = ft_lstnew(i);
//         ft_lstadd_back(&ma_stack, node);
//         i++;
//     }
//     *stack1= ma_stack;
//     return (stack1);
// }


// t_list   **fivenumbers(t_list  **stack1, t_list   **stack2, int long_a)
// {
//     t_list   *parcourir;
//     push(stack1, stack2, 'b', long_a);
//     push(stack1, stack2, 'b', long_a);
//     *stack1 = threenumbers(*stack1, long_a);
//     if ((*stack2)->nb < (*stack2)->next->nb)    // a voir si ce mouvement genere economie d autres mouvements sinon poubelle
//         (*stack2) = swap(*stack2, 'b', long_a);
//     push(stack2, stack1, 'a', long_a);
   
//     parcourir = (*stack1);
//     if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb > parcourir->next->next->next->nb))
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb < parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//         (*stack1) = swap(*stack1, 'a', long_a);
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     push(stack2, stack1, 'a', long_a);
//     parcourir = (*stack1);
//     if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb > parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb > parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rr(*stack1, 'a', long_a);
//         (*stack1) = swap(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//         (*stack1) = rotate(*stack1, 'a', long_a);
//     }
//     else if (((*stack1)->nb > parcourir->next->nb) && ((*stack1)->nb < parcourir->next->next->nb) 
//         && ((*stack1)->nb < parcourir->next->next->next->nb))
//     {
//         (*stack1) = swap(*stack1, 'a', long_a);
//     }
//     return (stack1);
// }
