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

void	check_line(char *line, t_rooms *r, t_lst *lst)
{
	if (line[0] == '#')
		check_hash(line, r, lst);
	else if (ft_strlen(line) == 0)
	{
		ft_printf("ERROR\n");
		exit (0);
	}
	else
		ft_printf("##%s##\n", line);
}

int		get_ants(char *line)
{
	int nb;
	int i;

	i = 0;
	get_next_line(0, &line);
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0)
		{
			ft_printf("Entree invalide\n");
			free(line);
			exit (0);
		}
		i++;
	}
	nb = ft_atoi(line);
	free(line);
	if (nb < 1)
	{
		ft_printf("Nombre de fourmis insuffisant\n");
		exit (0);
	}
	else
		return(nb);
}
