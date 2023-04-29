/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:58:16 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:58:21 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_position_in_a(t_list *stack_a, t_list *node)
{
    int pos;
    t_list   *stk;
    pos = INT_MAX;
    stk = stack_a;
    while (stack_a)
    {
        if (stack_a->final_position > node->final_position && stack_a->final_position < pos)
            pos = stack_a->final_position;
        stack_a = stack_a->next;
    }
    while (stk->final_position != pos)
        stk = stk->next;
    return (stk->temp_position);
}
int one_node_shifts(int pos, int size)
{
    int res;

    res = 0;
    if (pos <= (size) / 2)
        res = pos - 1;
    else
        res = size + 1 - pos;
    return (res);
}

int *shift_count_in_one_stack(t_list *stack, int size, int *tab)
{
    t_list   *s;
    int i;

    s = stack;
    i = 1;
    while (s)
    {
        tab[i] = one_node_shifts(s->temp_position, size);
        s = s->next;
        i++;
    }
    return (tab);
}

int *shift_count_both_stacks(t_list *stack_a, t_list *stack_b, int sizeB, int sizeA)
{
    int *shift_tab;
    t_list   *stk_b;
    t_list   *stk_a;
    int         pos;
    int i;

    i = 0;
    stk_b = stack_b;
    shift_tab = (int*)malloc((sizeB + 1) * sizeof(int));
    if (!shift_tab)
    {
        free(shift_tab);
        return (NULL);
    }
    shift_tab = shift_count_in_one_stack(stack_b, sizeB, shift_tab);
    i = 1;
    while (stack_b)
    {
        stk_a = stack_a;
        pos = find_position_in_a(stk_a, stack_b);
        shift_tab[i] = shift_tab[i] + one_node_shifts(pos, sizeA);
        stk_a = stack_a;
        stk_b = stk_b->next;
        i++;
        stack_b = stack_b->next;
    }
    return (shift_tab);
}

void    temporary_indexing(t_list **stack)
{
    t_list   *parcourir;
    int         i;

    i = 1;
    parcourir = *stack;
    while (parcourir)
    {
        parcourir->temp_position = i;
        i++;
        parcourir = parcourir->next;
    }
}

int find_position_in_b(t_list **stack_a, t_list **stack_b, int sizeA, int sizeB)
{

    int *shift_tab;
    int         i;
    int         min_shifts;
    
    min_shifts = 0;
    i = 1;

    shift_tab = shift_count_both_stacks(*stack_a, *stack_b, sizeB, sizeA);
    min_shifts = minimum(shift_tab, sizeB);
    i = 1;
    while (i <= sizeB)
    {
        if (shift_tab[i] == min_shifts)
            break;    
        i++;
    }
   free (shift_tab);
    return (i);
}
