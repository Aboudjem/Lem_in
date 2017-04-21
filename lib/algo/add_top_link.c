/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_top_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:03:36 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:38 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_links	*add_top_link(t_links *links, t_links *src, t_data *data)
{
	t_links *tmp;

	if ((tmp = ft_memalloc(sizeof(t_links))) == NULL)
		ft_exit(data);
	tmp->lst = src->lst;
	tmp->next = links;
	return (tmp);
}
