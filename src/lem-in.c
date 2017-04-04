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

int		get_rooms(char **line, t_rooms *r, t_lst **lst)
{
	t_lst *tmp;
		ft_putstr("split");
	get_next_line(0, &(*line));
	if(ft_splitnb(*line, ' ', r) == 1)
	{
		*lst = add_rooms(*lst, r->room, r->y, r->x);
		ft_printf("[%s][%d][%d]\n", r->room, r->y, r->x);
	}
	else
	{
		ft_putstr("split");
		
		ft_printf("Salle invalide");
		return(0);
	}
		ft_putstr("split");

	ft_printf("\n============================\n");
	tmp = *lst;
	ft_printf("--[NOM]--[Y]--[X]--\n");
	while(tmp)
	{
		ft_printf("--[%s]--[%d]--[%d]--\n", tmp->rooms, tmp->y, tmp->x);
		tmp = tmp->next;
	}
	ft_printf("\n============================\n");
	return(1);
}

int	check_hash(char *line, t_rooms *r, t_lst *lst)
{
	int i;

	i = 0;
	if (line[1] == '#')
	{
		if ((ft_strcmp("start", line + 2)) == 0)
		{
			ft_printf("[START]\n");
			while (get_rooms(&line, r, &lst) == 1)
			{
				ft_putstr("split");
				
				i++;
				ft_printf("[[%s]]\n\n", line);
			}
			if (i == 0)
			{
				ft_printf("\n[0 ROOM]\n");
				exit(0);
			}
			ft_printf("[END]");
		}
	}
	else
		ft_printf("[COMMENTAIRES]");
	return(0);
}

int		main()
{
	char *line;
	int i;
	t_rooms r;
	t_lst *lst;

	lst = NULL;
	line = NULL;	
	//Je recupere le nombre de fourmis
	i = get_ants(line);

	while (get_next_line(0, &line) > 0)
	{
		check_line(line, &r, lst);
		//	ft_printf("[%d], [%s]\n", i, line);
	}
}
