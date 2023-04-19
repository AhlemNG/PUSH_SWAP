

/****the progrqm will be cqlled qs follow : 
./checker 0 5 2 135
1- it takes a serie of integers 
        -does nothing if nothing is given
2- it waits to read commands from the standard input

3- it applys the commands read on the given list of numbers

--> if after applying the command the stack a is sorted and the stacl b is empty==> OK
--> if not : KO
--> if error in arguments : not an integer or duplicate .... free parsing

*/


/* how I SEE IT .
        1/ PARSING . DONE !
        2/ READ FROM THE STANDARD INPUT : use get_next_line
        3/ APPLY THE COMMANDS
        4/ READ NEXT LINE
                  READ------------->--------------------/APPLY
                    -                                       -
                    -       get_next_line_returns(what?)    -
                    -                                       -
                    -                                       -
                    APPLY-----------<--------------/READ_next/
                
        5/ FINISHED READING
        6/ FINISHED SORTING
        7/ SEE IF STACK A IS SORTED  ANS STACK B IS EMPTY => SHOW REULST--> OK
                                                                         2
                                                                         .
                                                                         KO
*/

/*interpreting the read line*/

#include "push_swap.h"

int tell_which_shift(char **line)
{
    if (ft_strcmp(*line, "pa") == 0)
        return (1);
    if (ft_strcmp(*line, "pb") == 0)
        return (2);
    if (ft_strcmp(*line, "sa") == 0)
        return (3);
    if (ft_strcmp(*line, "sb") == 0)
        return (4);
    if (ft_strcmp(*line, "ra") == 0)
        return (5);
    if (ft_strcmp(*line, "rb") == 0)
        return (6);
    if (ft_strcmp(*line, "rra") == 0)
        return (7);
    if (ft_strcmp(*line, "rrb") == 0)
        return (8);
    if (ft_strcmp(*line, "rr") == 0)
        return (9);
    if (ft_strcmp(*line, "rrr") == 0)
        return (10);
}

void apply_shifts(char *line, t_list **stack_a, t_list **stack_b)
{
    int which_shift;
    
    which_shift = tell_which_shift(line);
    if (which_shift == 1)
       push_a(stack_b, stack_a);
    if (which_shift == 2)
        push_b(stack_a, stack_b);
    if (which_shift == 3)
        swap_a(stack_a);
    if (which_shift == 4)
        swap_b(stack_b);
    if (which_shift == 5)
        rotate_a(stack_a);
    if (which_shift == 6)
        rotate_a(stack_b);
    if (which_shift == 7)
        reverse_rotate_a(stack_a);
    if (which_shift == 8)
        reverse_rotate_b(stack_a);
    if (which_shift == 9)
        rotate_a_and_b(stack_a, stack_b);
    if (which_shift == 10)
        reverse_rotate_a_and_b(stack_a, stack_b);   
}