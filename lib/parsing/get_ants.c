/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:09:47 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:09:48 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_ants(char *line, t_data *data)
{
	int nb;
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0 || i >= 10)
			ft_exit(data);
		i++;
	}
	nb = ft_atoi(line);
	if (nb < 1 || nb > 2147483647)
		exit(0);
	else
		return (nb);
}
