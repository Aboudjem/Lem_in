#include "lemin.h"

# define DEBUG 1
int	ft_error(int i)
{
	if (DEBUG == 1)
	{
		if (i == 1)
			ft_printf("[Error format]\n");
		else if (i == 2)
			ft_printf("[Error on Y/X]\n");
		else if(i == 5)
			ft_printf("[Invalid char '#' or 'L']\n");
		if (i == 3 || i == 4)
		{
			if (i == 3)
				ft_printf("[Invalid Input]\n");
			else if(i == 4)
				ft_printf("[Invalid amount of ants]\n");
			exit (0);
		}
	}
	return(0);
}
