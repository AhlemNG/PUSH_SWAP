/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:05:30 by anouri            #+#    #+#             */
/*   Updated: 2023/05/05 16:05:35 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_list **SRC, t_list **DST)
{
	t_list	*tmp;

	if (!*SRC)
		return ;
	tmp = *SRC;
	*SRC = (*SRC)->next;
	tmp->next = *DST;
	*DST = tmp;
}
