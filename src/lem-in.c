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

int		check_exist(char *s, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->rooms, s) == 0)
			return(0);
		lst = lst->next;
	}
	return(1);
}

int		get_rooms(char **line, t_rooms *r, t_lst **lst)
{
	ft_splitnb(*line, r);
	if (check_exist(r->room, *lst) == 1)
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

void	check_links(char *line, t_lst *lst)
{
	char **link;

	link = ft_strsplit(line, '-');
		ft_printf("-->[%s]<--\n", link[0]);
		ft_printf("-->[%s]<--\n", link[1]);

	if (check_exist(link[0], lst) == 0)
		ft_printf("-->[%s]<--\n", link[0]);
	else
		ft_printf("ERROR");
	if (check_exist(link[1], lst) == 0)
		ft_printf("-->[%s]<--\n", link[1]);
	else
		ft_printf("ERROR");
	exit(0);
	// if (check_exist()
}

int		main()
{
	char *line;
	int i;
	t_rooms r;
	t_lst *lst;
	int index;
	
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
				if (r.start == NULL || r.end == NULL)
				{
					ft_printf("ta pas oublie qqu chose ?\n");
					if (r.start)
						ft_printf("[%s]\n", r.start);
					if (r.end)
						ft_printf("[%s]\n", r.end);
					exit(0);
				}
			}

		}
		else if (index == 2)
		{
			check_links(line, lst);
		}

		ft_printf("[%d]\n", index);
	}
}
