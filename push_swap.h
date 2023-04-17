/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:47:56 by eghaffar          #+#    #+#             */
/*   Updated: 2023/04/16 13:04:29 by anouri           ###   ########.fr       */
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
	struct s_list *next; // pointeur vers le prochain node.
	int nb;                
		// la valeur qui sera recue apres atoi et inseree dans un node.
	int final_position;
	int temp_position;
}			t_list;

int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
void		ft_free(t_list *element);
// void		swap(t_list **element, char c, int long_a);
int			ft_lstsize(t_list **element);
// void		push(t_list **stack1, t_list **stack2, char c, int long_a);
void		print_value(t_list *lst);
// void		rotate(t_list **stack, char c, int log_a);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
// void		rr(t_list **stack, char c, int long_a);
t_list	*threenumbers(t_list *stack1, int long_a);
t_list	*convert_and_add(char **argv);
void		sort_two_numbers(t_list **stack, int long_a);
t_list	**fivenumbers(t_list **stack1, t_list **stack2, int long_a);
t_list	*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			sorted(t_list **stack_a);
void		swap_a_and_b(t_list **stack_a, t_list **stack_b);
void		rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
t_list	*mediane(t_list **stack_a, int long_a);
void		onehundrednumbers(t_list **stack_a, t_list **stack_b,
				int long_a);
void		indexing(t_list **stack_a);
t_list	*ft_lst_min(t_list *stack_a);
t_list	*copy_stack(t_list *stack_a);
t_list	*sort_stack(t_list *copy);
t_list	*sort_stack_array(t_list *copy);
void		ft_sort_int_tab(int *tab, int size);
int			switchcount(t_list *stack1, t_list *stack2);
t_list	*switchcompare(t_list *stack1, t_list *stack2);

void		presort(t_list **stack_a, t_list **stack_b, int long_a);
// int *shift_count_in_one_stack(t_list *stack_b, int rotate);
// int shift_count(t_list *stack_a, t_list *stack_b, int rot);
int			shift_count(t_list **stack_a, t_list **stack_b, int sizeA,
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
void	make_shifts_in_a(t_list **stack_a, int position_in_a, int long_a, int sizeA);
void	make_shifts_in_b(t_list **stack_b, int position_in_b, int long_a, int sizeB);
void 	make_rrr(t_list **stack_a, t_list **stack_b, int position_in_a, int position_in_b);


void	push(t_list **SRC, t_list **DST);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void    swap(t_list **stack);
void    swap_a(t_list **stack_a);
void    swap_b(t_list **stack_b);
void	rotate(t_list **stack);
void    rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void	reverse_rotate(t_list **stack);
void    reverse_rotate_a(t_list **stack_a);
void    reverse_rotate_b(t_list **stack_b);

#endif