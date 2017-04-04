/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 23:13:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 06:14:40 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	get_rooms(char *line, t_rooms *r)
{
	get_next_line(0, &line);
	ft_splitnb(line, ' ', r);
	ft_printf("[%s][%d][%d]\n", r->room, r->y, r->x);
}

int	check_hash(char *line, t_rooms *r)
{
	if (line[1] == '#')
		{
			if ((ft_strcmp("start", line + 2)) == 0)
			{
				ft_printf("[START]");
				get_rooms(line, r);
				return(1);
			}
			else if ((ft_strcmp("end", line + 2)) == 0)
			{
				ft_printf("[END]");
				return(2);
			}
			else
				ft_printf("[COMMENTAIRES]");
		}
	return(0);
}

void	check_line(char *line, t_rooms *r)
{
	if (line[0] == '#')
		check_hash(line, r);
	else if (ft_strlen(line) == 0)
	{
		ft_printf("ERROR");
		//exit (0);
	}
	else
		ft_printf("AUTRE");
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
			exit (0);
		i++;
	}
	nb = ft_atoi(line);
	free(line);
	if (nb < 1)
		exit (0);
	else
		return(nb);
}

int		main()
{
	char *line;
	int i;
	t_rooms r;
	line = NULL;	
	i = get_ants(line);
	while (get_next_line(0, &line))
	{
		check_line(line, &r);
		ft_printf("[%d], [%s]\n", i, line);
	}
}
