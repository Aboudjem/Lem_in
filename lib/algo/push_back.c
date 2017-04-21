/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:04:02 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:04:03 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		push_back(t_links *dest, t_links *src, t_data *data)
{
	if (dest)
	{
		while (dest->next)
			dest = dest->next;
		if ((dest->next = ft_memalloc(sizeof(t_links))) == NULL)
			ft_exit(data);
		dest->next->lst = src->lst;
		dest->next->next = NULL;
	}
}
