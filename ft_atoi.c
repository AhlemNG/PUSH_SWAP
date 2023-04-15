
#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	long long	nb;

	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	j = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j++;
		i++;
	}
	if ((nptr[i] < '0' || nptr[i] > '9'))
	{
		write(1,"Error\n", 7);
		exit(EXIT_FAILURE);	
	}
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nptr[i] - 48) + (nb * 10);
		i++;
	}
	if (j % 2 != 0)
		nb = -nb;
	if ( nb < INT_MIN || nb > INT_MAX)
		{
			write(1,"Error\n", 7);
			exit(EXIT_FAILURE);
		}
	else
		return (nb);
}