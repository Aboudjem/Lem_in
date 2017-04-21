/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:10:47 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:10:48 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	finish(t_data *data, t_links *tmp)
{
	t_lst	*end;
	t_links	*ptr;

	ptr = tmp;
	end = check_exist(data->end, data->lst);
	while (end->ant)
	{
		while (ptr)
		{
			if (ptr->lst->ant)
				ft_color(ptr->lst->ant, ptr->lst->name);
			ptr = ptr->next;
		}
		ft_putstr("\n");
		ptr = tmp;
		ft_advance_ants(ptr);
	}
}
