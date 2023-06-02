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

#include "push_swap_bonus.h"
#include "get_next_line.h"

void	free_line(char *line)
{
	write(1, "Error\n", 6);
	get_next_line(1, 1);
	free(line);
	exit(EXIT_FAILURE);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	tell_which_shift(char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		return (1);
	if (ft_strcmp(line, "pb\n") == 0)
		return (2);
	if (ft_strcmp(line, "sa\n") == 0)
		return (3);
	if (ft_strcmp(line, "sb\n") == 0)
		return (4);
	if (ft_strcmp(line, "ra\n") == 0)
		return (5);
	if (ft_strcmp(line, "rb\n") == 0)
		return (6);
	if (ft_strcmp(line, "rra\n") == 0)
		return (7);
	if (ft_strcmp(line, "rrb\n") == 0)
		return (8);
	if (ft_strcmp(line, "rr\n") == 0)
		return (9);
	if (ft_strcmp(line, "rrr\n") == 0)
		return (10);
	else
		return (-1);
}

static void	apply_shifts(char *line, t_list **stack_a, t_list **stack_b)
{
	int	which_shift;

	which_shift = tell_which_shift(line);
	if (which_shift == 1)
		push(stack_b, stack_a);
	if (which_shift == 2)
		push(stack_a, stack_b);
	if (which_shift == 3)
		swap(stack_a);
	if (which_shift == 4)
		swap(stack_b);
	if (which_shift == 5)
		rotate(stack_a);
	if (which_shift == 6)
		rotate(stack_b);
	if (which_shift == 7)
		reverse_rotate(stack_a);
	if (which_shift == 8)
		reverse_rotate(stack_a);
	if (which_shift == 9)
		rotate_bonus_a_and_b(stack_a, stack_b);
	if (which_shift == 10)
		reverse_rotate_bonus_a_and_b(stack_a, stack_b);
	if (which_shift == -1)
		free_line(line);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	if (argc > 2)
	{
		stack_a = get_list(argc, argv);
		stack_b = NULL;
		line = malloc(1 * sizeof(char));
		while (line != NULL)
		{
			free(line);
			line = get_next_line(0, 0);
			if (!line)
				break ;
			apply_shifts(line, &stack_a, &stack_b);
		}
		if (sorted(&stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
