#include "lemin.h"

size_t		len_str(char *s)
{
	size_t i;

	i = 0;
	if (s[0] == '#' || s[0] == 'L')
		return(ft_error(5));
	while(s[i] != ' ' && s[i] != '\0')
		i++;
	return(i);
}

int		count_space(char *s)
{
	int i;
	int space;

	space = 0;
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == ' ')
			space++;
		i++;
	}
	return(space);
}

int		check_nb(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == ' ' || ft_isdigit(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
