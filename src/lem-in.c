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

int		check_exist(t_rooms *r, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->rooms, r->room) == 0)
			return(0);
		lst = lst->next;
	}
	return(1);
}

int		get_rooms(char **line, t_rooms *r, t_lst **lst)
{
	ft_splitnb(*line, r);
	if (check_exist(r, *lst) == 1)
		*lst = add_rooms(*lst, r->room,r->y,r->x);
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

void	check_startend(char **line, t_rooms *r)
{
	if (check_line(*line) == 2)
	{
		get_next_line(0, line);
		if (check_room(*line) == 1)
			r->start = ft_strdup(*line);
	}
	else if (check_line(*line) == 3)
	{
		get_next_line(0, line);
		if (check_room(*line) == 1)
			r->end = ft_strdup(*line);
	}
}

int		main()
{
	char *line;
	int i;
	t_rooms r;
	t_lst *lst;
	int index;
	
	// char *start;
	// char *end;
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
		else if (index == 1)
		{
			check_startend(&line, &r);
			if (check_room(line) == 1)
				get_rooms(&line, &r, &lst);
			if ((check_room(line) == 0) && ((check_line(line) != 2) && (check_line(line) != 3)))
			{
				if (!lst)
					exit(0);	
				index++;
			}
		}
		else if (index == 2)
		{
			if (r.start == NULL || r.end == NULL)
				ft_printf("ta pas oublie qqu chose ?\n");
			ft_printf("[%s]--[%s]\n", r.start, r.end);
			ft_putstr("COOL");
		}

		ft_printf("[%d]\n", index);
	}
}
