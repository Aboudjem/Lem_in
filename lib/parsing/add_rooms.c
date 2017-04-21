/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:08:46 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:08:47 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_rooms(t_data *data, t_lst *ptr)
{
	t_lst *tmp;

	tmp = data->lst;
	if (tmp == NULL)
	{
		data->lst = ptr;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ptr;
}
