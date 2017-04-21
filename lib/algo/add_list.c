/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:03:30 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:32 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_links		*add_list(t_links *dest, t_links *src, t_data *data)
{
	while (src)
	{
		if (src->lst->value == 0)
		{
			if (!dest)
			{
				if ((dest = ft_memalloc(sizeof(t_links))) == NULL)
					ft_exit(data);
				dest->lst = src->lst;
				dest->next = NULL;
			}
			else
				push_back(dest, src, data);
		}
		src = src->next;
	}
	return (dest);
}
