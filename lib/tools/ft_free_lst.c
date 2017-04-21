/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:08:25 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:08:25 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_lst(t_lst *lst)
{
	t_lst *tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst->next;
		while (lst->links)
		{
			free(lst->links);
			lst->links = lst->links->next;
		}
		free(lst->name);
		free(lst);
		lst = tmp;
	}
}
