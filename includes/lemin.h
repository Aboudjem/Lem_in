/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 05:59:47 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 06:35:12 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct	s_rooms
{
	int		y;
	int		x;
	char	*room;
}			t_rooms;


typedef struct	s_lst
{
	int				x;
	int				y;
	char			*rooms;
	struct s_lst	*next;
}					t_lst;
/*
** ft_splitnb.c
 */
t_lst	*add_rooms(t_lst *lst, char *str, int y, int x);
int		get_nb(char *s, char c);
int		get_str(char *s, char c);
int		ft_splitnb(char *s, char c, t_rooms *r);

/*
** checking.c
 */
void	check_line(char *line, t_rooms *r, t_lst *lst);
int		get_ants(char *line);

int		check_hash(char *line, t_rooms *r, t_lst *lst);

#endif
