/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:03:56 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:57 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		init_tree(t_lst *start, t_lst *end, t_data *data)
{
	t_links	*tmp_links;
	t_links	*links;
	int		i;

	i = 1;
	links = start->links;
	start->value = 1;
	while (links && end->value == 0)
	{
		tmp_links = NULL;
		i++;
		while (links)
		{
			if (links->lst->value == 0)
			{
				links->lst->value = i;
				tmp_links = add_list(tmp_links, links->lst->links, data);
			}
			links = links->next;
		}
		clean_list(links);
		links = tmp_links;
	}
}
