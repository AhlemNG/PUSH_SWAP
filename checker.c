/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:53:36 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 11:53:42 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclue "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
    size_t  n;

    n = ft_strlen(s1);
	i = 0;
	while (i < (n - 1) && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include "push_swap.h"

int tell_which_shift(char **line)
{
    if (ft_strcmp(*line, "pa\n") == 0)
        return (1);
    if (ft_strcmp(*line, "pb\n") == 0)
        return (2);
    if (ft_strcmp(*line, "sa\n") == 0)
        return (3);
    if (ft_strcmp(*line, "sb\n") == 0)
        return (4);
    if (ft_strcmp(*line, "ra\n") == 0)
        return (5);
    if (ft_strcmp(*line, "rb\n") == 0)
        return (6);
    if (ft_strcmp(*line, "rra\n") == 0)
        return (7);
    if (ft_strcmp(*line, "rrb\n") == 0)
        return (8);
    if (ft_strcmp(*line, "rr\n") == 0)
        return (9);
    if (ft_strcmp(*line, "rrr\n") == 0)
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
      else
    {
        free(stack_a);
        free(stack_b);
        free(line);
        get_next_line(1,1);
        write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    t_list **stack_a;
    t_list **stack_b;
    char    *line;
  
    if (argc > 1)
    {
        stack_a = ft_get_list(argc, argv);
        stack_b = NULL;    
        line = malloc (1 * sizeof(char));
        while (line != NULL)
        {
            free(line);
            line = get_next_line(0,0);
            if (!line)
                break;
            apply_shifts(line, stack_a, stack_b);
        }
        if (sorted(stack_a))
            write(1,"OK\n", 3);
        else
            write(1,"KO\n", 3);
    }
    return (0);
}
