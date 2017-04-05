/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 23:13:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 07:55:24 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	print_lst(t_lst *lst)
{
	t_lst *tmp;
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		ft_printf("--[%s]--[%d]--[%d]--\n", tmp->rooms, tmp->y, tmp->x);
		tmp = tmp->next;
	}
}

int		get_rooms(char **line, t_rooms *r, t_lst **lst)
{
	ft_printf("[ENTRE]\n");
	ft_splitnb(*line, r);
	ft_printf("[splut]\n");
	*lst = add_rooms(*lst, r->room,r->y,r->x);
	ft_printf("[add_room]\n");
	if (*lst)
		print_lst(*lst);
	return(1);
}

int		check_line(char *line)
{
	if (line[0] == '\0')
		return (0);
	if ((line[0] && line[1]) && line[0] == '#' && line[1] != '#') 
		return (1);
	else if ((line[0] && line[1]) && line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (2);
		else if (ft_strcmp(line, "##end") == 0)
			return (3);
		else
			return (1);
	}
	return (0);
}

int		main()
{
	char *line;
	int i;
	t_rooms r;
	t_lst *lst;
	int index;
	
	char *start;
	lst = NULL;
	line = NULL;

	index = 0;
	//Je recupere le nombre de fourmis
	ft_printf("[%d]\n", index);
	while (get_next_line(0, &line) > 0)
	{
		if (index == 0 && (i = (get_ants(line)) > 0))
			index++;
		else if (check_line(line) == 1)
			ft_printf("[COMMENTAIRES]\n");
		else if (check_line(line) == 2 && index == 1)
		{
			index++;
			ft_printf("[Start]\n");
		}
		else if (index == 2 && check_room(line, &index) == 1)
		{
			start = ft_strdup(line);
			get_rooms(&line, &r, &lst);
			ft_putstr("coucou");
			index++;
		}
		else if (index == 3 && check_room(line, &index) == 1)
		{
			get_rooms(&line, &r, &lst);
		}
		else if (index == 4)
			ft_printf("[Fin ROOM]\n");
		else
			ft_putstr("FINISH");	
		ft_printf("[%d]\n", index);
	}
}
