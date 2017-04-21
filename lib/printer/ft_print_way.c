/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:10:57 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:10:58 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_way(t_data *data, t_links *tmp)
{
	t_links	*ptr;
	int		i;

	i = 0;
	ptr = tmp->next;
	while (i < data->nb_ant)
	{
		i++;
		if (ptr->lst->ant == 0)
			ptr->lst->ant = i;
		while (ptr)
		{
			if (ptr->lst->ant)
				ft_color(ptr->lst->ant, ptr->lst->name);
			ptr = ptr->next;
		}
		ft_putstr("\n");
		ptr = tmp->next;
		ft_advance_ants(ptr);
	}
	finish(data, tmp);
}
