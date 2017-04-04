/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 04:57:46 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 07:54:58 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*add_rooms(t_lst *lst, char *str, int y, int x)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->rooms = ft_strdup(str);
		tmp->next = lst;
	}
	return (tmp);
}

int		get_str(char *s, char c)
{
	int i;

	i = 0;
	if (s[0] == '#' || s[0] == 'L')
	{
		ft_printf("Nom de salle interdit\n");
		return(0);
	}

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
	if (!s || i == 0)
		return (0);
	if (get_nb(s + i,c) != 2)
		return (0);
	r->room = ft_strsub(s, 0, i);
	r->y = ft_atoi(s+i);
	r->x = ft_atoi(s+(i + ft_len_int(r->y) + 1));
	return (1);
}
