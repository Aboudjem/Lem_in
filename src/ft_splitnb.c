/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 04:57:46 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 06:23:57 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_str(char *s, char c)
{
	int i;

	i = 0;
	while(s[i] != c)
		i++;
	return(i);
}

int		get_nb(char *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;

	while(s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		else if(ft_isdigit(s[i]) == 0 && s[i] != c)
			return (0);
		i++;
	}
	return (count);
}
			

int		ft_splitnb(char *s, char c, t_rooms *r)
{
	int i;

	i = get_str(s,c);
	if (!s)
		return (0);
	if (get_nb(s + i,c) != 2)
			return (0);
	r->room = ft_strsub(s, 0, i);
	r->y = ft_atoi(s+i);
	r->x = ft_atoi(s+(i + ft_len_int(r->y) + 1));
	ft_putstr("ICI");
	return (1);
}
