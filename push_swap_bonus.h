/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:32 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:06:37 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

/*****************parsing**********************/

int					is_digit(char c);
int					is_a_zero(const char *str);
int					is_number(char *str);
int					no_doublon(char **str);
int					check_if_valid(char **argv);
int					ft_check_doublon(t_list *lst, int content);
int					str_nb_compare(const char *s1, const char *s2);
long long			ft_atoi(const char *nptr);

/*****************list**********************/
int					sorted(t_list **stack_a);
int					ft_lstsize(t_list **element);
void				ft_free(t_list *element);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*get_list(int argc, char **argv);
t_list				*ft_lstnew(int content);
/**********shifts**********/
void				push(t_list **SRC, t_list **DST);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				rotate_bonus(t_list **stack);
void				reverse_rotate(t_list **stack);
void				reverse_rotate_bonus(t_list **stack);
void				rotate_bonus_a_and_b(t_list **stack_a, t_list **stack_b);
void				reverse_rotate_bonus_a_and_b(t_list **stack_a,
						t_list **stack_b);
void				swap_bonus_a_and_b(t_list **stack_a, t_list **stack_b);
void				rotate_bonus_a_and_b(t_list **stack_a, t_list **stack_b);
void				reverse_rotate_bonus_a_and_b(t_list **stack_a,
						t_list **stack_b);
void				make_bonus_rr(t_list **stack_a, t_list **stack_b,
						t_list **temp_a, t_list **temp_b);
void				make_bonus_rrr(t_list **stack_a, t_list **stack_b,
						t_list **temp_a, t_list **temp_b);

#endif
