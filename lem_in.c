/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:23:23 by ireva             #+#    #+#             */
/*   Updated: 2017/10/26 16:04:13 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			search_node(t_listz **room_list, int i)
{
	t_listz		*next;
	t_listz		*current;
	int			j;

	j = 0;
	current = *room_list;
	next = *room_list;
	while (ft_strcmp(g_lem.best_way_arr[i], next->name) != 0)
		next = next->next;
	while (ft_strcmp(g_lem.best_way_arr[i - 1], current->name) != 0)
		current = current->next;
	if (current->ants != -1)
	{
		if (current->start == 1)
		{
			g_lem.flag++;
			next->ants = g_lem.flag;
		}
		else
			next->ants = current->ants;
		writter(next);
	}
	norm(&current);
}

void			place_ants(t_listz **room_list)
{
	int			i;
	t_listz		*end;
	t_listz		*temp;
	int			j;

	end = NULL;
	g_lem.flag = 0;
	i = g_lem.best_arr_size - 1;
	(*room_list)->ants = g_lem.ants;
	temp = *room_list;
	write(1, "\n", 1);
	norma(room_list, &end, i);
	j = i;
	while (end->ants != g_lem.ants)
	{
		while (i > 0)
		{
			search_node(room_list, i);
			i--;
		}
		write(1, "\n", 1);
		i = j;
	}
}

void			if_placing(t_listz **room_list)
{
	int i;

	i = 0;
	if (g_lem.best_way_arr != NULL)
		while (g_lem.best_way_arr[i])
			i++;
	else
		time_to_exit();
	if (i > 0)
		g_lem.nod_count = i;
	if (g_lem.best_way_arr != NULL)
		place_ants(room_list);
}

void			freedom_for_nods(t_listz **room_list)
{
	if (room_list != NULL)
	{
		while ((*room_list))
		{
			if ((*room_list)->name != NULL)
				free((*room_list)->name);
			free(*room_list);
			(*room_list) = (*room_list)->next;
		}
	}
}

int				main(void)
{
	char	*line;
	int		fd;
	t_listz	*room_list;

	line = NULL;
	room_list = NULL;
	fd = 0;
	init_ints();
	(fd == -1) ? time_to_exit() : 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		validation(line, fd, &room_list);
		if (line != NULL)
			free(line);
	}
	(room_list == NULL) ? time_to_exit() : 0;
	(g_lem.links == 0) ? time_to_exit() : 0;
	(g_lem.ants > 2147483646) ? time_to_exit() : 0;
	init();
	way_s_e(&room_list);
	check_way(g_lem.w_start);
	if_placing(&room_list);
	freedom_for_nods(&room_list);
	return (0);
}
