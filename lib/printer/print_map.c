/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 05:19:08 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 05:19:56 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_color(int nb, char *line)
{
	ft_putstr("\e[38;5;");
	ft_putnbr(nb);
	ft_putstr("m");
	ft_putstr(line);
	ft_putstr(STOP);
}

void			print_map(t_data *data, char *line)
{
	if (check_line(line) == 1)
	{
		ft_putstr(ITALIC);
		print_color(154, line);
	}
	else if (check_line(line) == 2 || check_line(line) == 3)
		print_color(161, line);
	else if (!CHECK_BIT(data->status, ANTS) && get_ants(line, data) > 0)
	{
		ft_putstr(UNDERLINE);
		print_color(220, line);
	}
	else if (!CHECK_BIT(data->status, ROOMS) && count_char(line, '-') == 0)
		print_color(15, line);
	else if (!CHECK_BIT(data->status, LINKS))
	{
		ft_putstr(ITALIC);
		print_color(201, line);
	}
	ft_putstr("\n");
}
