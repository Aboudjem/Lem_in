/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_exist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:09:42 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:09:43 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst		*check_exist(char *s, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, s) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
