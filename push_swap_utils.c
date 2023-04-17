#include "push_swap.h"

int	minimum(int	*tab, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 1;
	while (i <= size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int ft_lstsize(t_list **element)
{
    t_list	*parcourir;
	int i;

	parcourir = *element;
    i = 0;
	while(parcourir)
    {
        parcourir = parcourir->next;
        i++;
    }
    return(i);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst->next);
	free (lst);
}

void    ft_free(t_list *element)
{
    t_list	*temp;

	// if (!element)
	// {
	// 	if (*element)
	// 		*element = NULL;
	// 	return ;
	// }
	while (element)
	{
		temp = (element)->next;
	    free (element);
		element = temp;
	}
	element = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst) 
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while ((temp -> next) != NULL)
		temp = temp -> next;
	temp -> next = new;
}

int	sorted(t_list **stack_a)
{
	t_list	*parcourir;

	parcourir = *stack_a;
	
	while (parcourir->next)
	{
		if (parcourir->nb > parcourir->next->nb)
			return (0);
		parcourir = parcourir->next;
	}
	return (1); 
}

t_list *mediane(t_list **stack_a, int long_a)
{
	t_list	*parcourir;
	t_list	*mediane;
	int	inferieur_mediane;
	int	superieur_mediane;

	parcourir = (*stack_a)->next;
	mediane = *stack_a;

	inferieur_mediane = long_a;
	superieur_mediane = long_a;
	while (mediane)
	{
		parcourir = (*stack_a)->next;
		while (parcourir)
		{
			if (mediane->nb > parcourir->nb)
			{
				superieur_mediane--;
				parcourir = parcourir->next;
			}
			else if (mediane->nb < parcourir->nb)
			{	
				inferieur_mediane--;
				parcourir = parcourir->next;
			}
			if ((inferieur_mediane + superieur_mediane) == (long_a + 1)) 
			{
				mediane->next = NULL;
				return (mediane);
			}
			parcourir = parcourir->next;
		}
		mediane = mediane->next;
	}
	return (mediane);
}