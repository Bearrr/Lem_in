/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:36:23 by ireva             #+#    #+#             */
/*   Updated: 2017/10/26 15:03:20 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_end(char *line, int fd, t_listz **room_list)
{
	int			i;

	i = 0;
	if (g_lem.end == 2)
		time_to_exit();
	if (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (line[0] == '\0')
			time_to_exit();
		if (line[0] == '#' || (line[0] >= 0 && line[0] <= 32))
			time_to_exit();
		g_lem.free_end = 1;
		g_lem.end = 1;
		if (ft_words(line, ' ') == 3 && count_spaces(line) == 2)
			if_room(line, room_list);
	}
}

void			check_start(char *line, int fd, t_listz **room_list)
{
	int			i;

	i = 0;
	if (g_lem.start == 2)
		time_to_exit();
	if (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (line[0] == '\0')
			time_to_exit();
		if (line[0] == '#' || (line[0] >= 0 && line[0] <= 32))
			time_to_exit();
		g_lem.start = 1;
		g_lem.free_start = 1;
		if (ft_words(line, ' ') == 3 && count_spaces(line) == 2)
			if_room(line, room_list);
		else
			time_to_exit();
	}
}

void			if_hash(char *line, int fd, t_listz **room_list)
{
	if ((line[0] == '#' && line[1] == '#'))
	{
		if (ft_strcmp(line, "##start") == 0)
			check_start(line, fd, room_list);
		else if (ft_strcmp(line, "##end") == 0)
			check_end(line, fd, room_list);
	}
	else if (line[0] == '#')
		return ;
	else
		time_to_exit();
}

void			validation_norm(char *line, t_listz **room_list)
{
	int i;

	i = 0;
	if (g_lem.ants == 0 && (line[i] >= 'a' && line[i] <= 'z'))
		time_to_exit();
	else if (ft_words(line, ' ') == 3
			&& count_spaces(line) == 2 && line[0] != '#')
	{
		if_room(&line[i], room_list);
		g_lem.f++;
	}
	if (count_defis(line) == 1 && line[0] != '#')
	{
		if_link(line, room_list);
		g_lem.f++;
	}
	else if (count_defis(line) > 1)
		time_to_exit();
	if (g_lem.f == 0)
		time_to_exit();
}

void			validation(char *line, int fd, t_listz **room_list)
{
	int			i;

	i = 0;
	g_lem.f = 0;
	g_lem.free_start = 0;
	g_lem.free_end = 0;
	if (line[0] == '\0' || line[0] == '\n')
		time_to_exit();
	if (line[0] == '#')
	{
		if_hash(&line[i], fd, room_list);
		g_lem.f++;
	}
	if (g_lem.ants == 0 && (line[i] >= '1' && line[i] <= '9'))
	{
		if (if_alpha(line) == 0)
		{
			g_lem.ants = ft_atoi(line);
			g_lem.f++;
		}
		else
			time_to_exit();
	}
	validation_norm(line, room_list);
}
