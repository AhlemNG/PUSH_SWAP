/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:47:56 by eghaffar          #+#    #+#             */
/*   Updated: 2023/04/29 11:55:15 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	int				nb;
	int				target_position;
	int				shift_direction;
	int				cost;
	int				total_cost;
	int				final_position;
	int				temp_position;
}					t_list;

/*****************parsing*****************************************/

int					is_digit(char c);
int					is_a_zero(const char *str);
int					is_number(char *str);
int					no_doublon(char **str);
int					check_if_valid(char **argv);
int					ft_check_doublon(t_list *lst, int content);
int					str_nb_compare(const char *s1, const char *s2);
long long			ft_atoi(const char *nptr);

/*****************list***********************************************/
int					sorted(t_list **stack_a);
int					ft_lstsize(t_list **element);
void				ft_free(t_list *element);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*get_list(int argc, char **argv);
t_list				*ft_lstnew(int content);
/**********shifts***************************************************/
void				push(t_list **SRC, t_list **DST);
void				swap(t_list **stack);
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				rotate(t_list **stack);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				reverse_rotate(t_list **stack);
void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				rotate_bonus_a_and_b(t_list **stack_a, t_list **stack_b);
void				reverse_rotate_bonus_a_and_b(t_list **stack_a,
						t_list **stack_b);
void				push_a(t_list **stack_b, t_list **stack_a);
void				push_b(t_list **stack_a, t_list **stack_b);
void				swap_a_and_b(t_list **stack_a, t_list **stack_b);
void				rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void				make_shifts_in_a(t_list **stack_a, t_list **temp_a);
void				make_shifts_in_b(t_list **stack_b, t_list **temp_b);
void				reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void				make_shifts(t_list **stack_a, t_list **stack_b,
						int cheapest_position);
void				make_rr(t_list **stack_a, t_list **stack_b, t_list **temp_a,
						t_list **temp_b);
void				make_rrr(t_list **stack_a, t_list **stack_b,
						t_list **temp_a, t_list **temp_b);
/*****************indexing************************************************/
void				indexing(t_list **stack_a);
void				temporary_indexing(t_list **stack);
/*****************sorting*************************************************/
void				sort_two_numbers(t_list **stack, int long_a);
void				sort_three_numbers(t_list **stack1, int long_a);
void				presort(t_list **stack_a, t_list **stack_b, int long_a);
void				main_sort(t_list **stack_a, t_list **stack_b, int long_a);
void				final_sort(t_list **stack, int long_a);
/*****************cost*****************************************************/
void				assign_cost_and_direction(t_list **stack, int size);
void				calculate_total_cost(t_list **stack_a, t_list **stack_b);
int					get_min_cost(t_list *stack_b);
/******************position*************************************************/
void				give_final_position(t_list **stack, int *fp, long *min);
void				assign_target_position(t_list *stack_a, t_list **stack_b);
int					find_position_in_a(t_list *stack_a, t_list *node);
int					get_cheapest_position(t_list *stack_b);

#endif
