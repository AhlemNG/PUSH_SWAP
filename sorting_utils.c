#include "push_swap.h"
void   indexing(t_list **stack_a)
{
    t_list   *parcourir;
    long         min;
    int fp;
    int a;

    parcourir = *stack_a;
    while (parcourir)
    {
        parcourir->final_position = 0;
        parcourir = parcourir->next;
    }
    fp = 0;
    a = 1;
    while(a != 0)
    {
        parcourir = *stack_a;        
        min = 2147483649;
        while(parcourir)
        {
            if (parcourir->nb < min && parcourir->final_position == 0)
                min = parcourir->nb;
            parcourir = parcourir->next;
        }
        parcourir = *stack_a;
    
        while(parcourir)
        {    
            if(parcourir->nb == min)
            {
                fp++;
                parcourir->final_position = fp; 
            }
            parcourir = parcourir->next;
        }
        parcourir = *stack_a;
        while (parcourir)
        {
            a = 0;
            if (parcourir->final_position == 0)
            {
                a = 1;
                break;
            }
            parcourir = parcourir->next;
        }
    }
}