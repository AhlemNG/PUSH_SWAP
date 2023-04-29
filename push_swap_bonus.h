/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:12:35 by anouri            #+#    #+#             */
/*   Updated: 2023/04/29 17:12:39 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <bsd/string.h>
# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list *next;
	int nb;                

	int final_position;
	int temp_position;
}			t_list;
int	cost(int position, int size, int *direction);
long long 			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
void		ft_free(t_list *element);

int			ft_lstsize(t_list **element);

void		print_value(t_list *lst);

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void  sort_three_numbers(t_list **stack1, int long_a);
void		sort_two_numbers(t_list **stack, int long_a);
t_list	**fivenumbers(t_list **stack1, t_list **stack2, int long_a);
t_list	*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			sorted(t_list **stack_a);
void		swap_a_and_b(t_list **stack_a, t_list **stack_b);
void		rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		onehundrednumbers(t_list **stack_a, t_list **stack_b,
				int long_a);
void		indexing(t_list **stack_a);
t_list	*ft_lst_min(t_list *stack_a);
t_list	*copy_stack(t_list *stack_a);
t_list	*sort_stack(t_list *copy);
t_list	*sort_stack_array(t_list *copy);
void		ft_sort_int_tab(int *tab, int size);


void		presort(t_list **stack_a, t_list **stack_b, int long_a);

int			find_position_in_b(t_list **stack_a, t_list **stack_b, int sizeA,
				int sizeB);
void		push_swap(t_list **stack_a, t_list **stack_b, int long_a);
void		temporary_indexing(t_list **stack);
int			minimum(int *tab, int size);
void		make_shifts(t_list **stack_a, t_list **stack_b,
				int long_a);
int			find_position_in_a(t_list *stack_a, t_list *node);
int			one_node_shifts(int pos, int size);
int			*shift_count_in_one_stack(t_list *stack, int size, int *tab);
int			*shift_count_both_stacks(t_list *stack_a, t_list *stack_b,int sizeB, int sizeA);
t_list  *get_list(int argc, char **argv);
void	make_shifts_in_a(t_list **stack_a, int *cost_in_a, int direction);
void	make_shifts_in_b(t_list **stack_b, int *cost_in_b, int direction);
void	make_rr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b);
void	make_rrr(t_list **stack_a, t_list **stack_b, int *cost_in_a, int *cost_in_b);
void	push(t_list **SRC, t_list **DST);
void	push_a_bonus(t_list **stack_b, t_list **stack_a);
void	push_b_bonus(t_list **stack_a, t_list **stack_b);
void    swap(t_list **stack);
void    swap_a_bonus(t_list **stack_a);
void    swap_b_bonus(t_list **stack_b);
void	rotate(t_list **stack);
void    rotate_a_bonus(t_list **stack_a);
void    rotate_b_bonus(t_list **stack_b);
void	reverse_rotate(t_list **stack);
void    reverse_rotate_a_bonus(t_list **stack_a);
void    reverse_rotate_b_bonus(t_list **stack_b);
int		ft_check_doublon(t_list *lst, int content);

/******* sorting*******/

void real_sort(t_list **stack_a, t_list **stack_b, int position_in_a, int position_in_b);

void final_sort(t_list **stack, int long_a);

#endif
