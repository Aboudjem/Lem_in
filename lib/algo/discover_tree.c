/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discover_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:03:47 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:48 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_links	*discover_tree(t_lst *end, t_data *data)
{
	int		i;
	t_links	*links;
	t_links	*ptr;

	links = end->links;
	i = end->value;
	if ((ptr = ft_memalloc(sizeof(t_links))) == NULL)
		ft_exit(data);
	ptr->lst = end;
	ptr->next = NULL;
	while (links && i > -1)
	{
		if (links->lst->value == i - 1)
		{
			ptr = add_top_link(ptr, links, data);
			links = links->lst->links;
			i--;
		}
		else
			links = links->next;
	}
	return (ptr);
}
