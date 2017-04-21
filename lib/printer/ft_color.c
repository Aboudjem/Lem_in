/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:10:53 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:10:54 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_color(int i, char *str)
{
	ft_putstr("\e[38;5;");
	ft_putnbr(160 + (i % 20));
	ft_putstr("m");
	ft_putstr("L");
	ft_putnbr(i);
	ft_putstr("-");
	ft_putstr(str);
	ft_putstr(STOP);
}
