/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 23:13:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 07:55:24 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"
# include <limits.h>
int		get_ants(char *line)
{
	int nb;
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0)
		{
			return(ft_error(3));
		}
		i++;
	}
	nb = ft_atoi(line);
	free(line);
	ft_putnbr(nb);
	if (nb < 1 || nb > INT_MAX)
		return(ft_error(4));
	else
		return(nb);
}
