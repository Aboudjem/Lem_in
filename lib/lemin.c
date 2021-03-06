/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:06:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 05:18:14 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			next_step(char *line, t_data *data)
{
	if ((check_room(line) == 0) &&
			((check_line(line) != 2) && (check_line(line) != 3)))
	{
		if (!data->lst || data->start == NULL || data->end == NULL)
			ft_exit(data);
		if (get_links(line, data))
			return (1);
		else
			ft_exit(data);
	}
	return (0);
}

static int	check_end(t_lst *lst)
{
	while (lst)
	{
		if (lst->links)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			get_links(char *line, t_data *data)
{
	if (count_char(line, '-') == 1)
		return (check_links(line, data->lst, data));
	else if (check_end(data->lst))
	{
		data->status |= FINISH;
		find_way(data);
	}
	else
		ft_exit(data);
	return (0);
}

int			main(void)
{
	char	*line;
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	line = NULL;
	while (get_next_line(0, &line) >= 0)
	{
		if (!CHECK_BIT(data->status, FINISH))
			print_map(data, line);
		if (!CHECK_BIT(data->status, ANTS) &&
				(data->nb_ant = get_ants(line, data)) > 0)
			data->status |= ANTS;
		else if (CHECK_BIT(data->status, ANTS) &&
				(!CHECK_BIT(data->status, ROOMS)) && check_line(line) != 1)
			check_startend(line, data);
		else if (CHECK_BIT(data->status, ROOMS) && check_line(line) != 1)
			get_links(line, data);
		free(line);
	}
}
