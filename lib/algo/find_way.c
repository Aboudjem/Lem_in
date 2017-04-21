/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:03:51 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:52 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			find_way(t_data *data)
{
	t_lst	*start;
	t_lst	*end;
	t_links	*tmp;

	start = check_exist(data->start, data->lst);
	end = check_exist(data->end, data->lst);
	if (!start || !end)
		return (0);
	init_tree(start, end, data);
	if (end->value != 0)
	{
		tmp = discover_tree(end, data);
		ft_print_way(data, tmp);
		clean_list(tmp);
		exit(0);
	}
	else
		ft_exit(data);
	data->status = 0;
	return (end->value);
}
