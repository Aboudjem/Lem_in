/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:06:13 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:06:14 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (!str)
		exit(0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
