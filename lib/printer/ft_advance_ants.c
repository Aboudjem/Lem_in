/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advance_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:10:50 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:10:51 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_advance_ants(t_links *ptr)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while (ptr)
	{
		value = ptr->lst->ant;
		ptr->lst->ant = i;
		i = value;
		ptr = ptr->next;
	}
}
