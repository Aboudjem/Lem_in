#include "lemin.h"

# define DEBUG 1
int	ft_error(int i)
{
	if (DEBUG == 1)
	{
		if (i == 1)
			ft_printf("[Error Format must be [Str]_[Y]_[X] ]\n");
		else if (i == 2)
			ft_printf("[Error on input of Y/X]\n");
		else if(i == 5)
			ft_printf("[Invalid char '#' or 'L' for room's name]\n");
		if (i == 3)
			ft_printf("[Invalid Input]\n");
		else if(i == 4)
			ft_printf("[Not enough ants]\n");
		// return(0);
	}
		exit (0);
	return(0);
}
