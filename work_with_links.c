/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:09:22 by ireva             #+#    #+#             */
/*   Updated: 2017/10/26 15:13:09 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_index(t_listz **room_list, int flag)
{
	int			i;
	t_listz		*temp;

	i = 0;
	temp = *room_list;
	while (temp)
	{
		if (flag == 1)
			if (g_lem.temp_name == temp->name)
				break ;
		if (flag == 2)
			if (g_lem.temp_sname == temp->name)
				break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

void			wr_links(t_listz **room_list)
{
	int			i;
	int			j;

	g_lem.links = 1;
	i = check_index(room_list, 1);
	j = check_index(room_list, 2);
	if (g_lem.net[i][j] != 1)
		g_lem.net[i][j] = 1;
	else
		time_to_exit();
	if (g_lem.net[j][i] != 1)
		g_lem.net[j][i] = 1;
	else
		time_to_exit();
}

void			check_link_sname(char *line, t_listz **room_list)
{
	t_listz		*temp;
	int			i;
	int			k;

	i = 0;
	k = 0;
	temp = *room_list;
	while (line[i] != '-')
		i++;
	i++;
	while (temp)
	{
		if (ft_strcmp(&line[i], g_lem.temp_name) == 0)
			time_to_exit();
		if (ft_strcmp(temp->name, &line[i]) == 0)
		{
			g_lem.temp_sname = temp->name;
			wr_links(room_list);
			k++;
		}
		temp = temp->next;
	}
	if (k == 0)
		time_to_exit();
}

void			check_link_name(char *line, t_listz **room_list)
{
	t_listz		*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	g_lem.k = 0;
	temp = *room_list;
	while (line[i] != '-')
		i++;
	while (temp)
	{
		while (temp->name[g_lem.k])
			g_lem.k++;
		if (ft_strncmp(temp->name, line, i) == 0 && i == g_lem.k)
		{
			g_lem.temp_name = temp->name;
			check_link_sname(line, room_list);
			j++;
			break ;
		}
		g_lem.k = 0;
		temp = temp->next;
	}
	(j == 0) ? time_to_exit() : 0;
}

void			if_link(char *line, t_listz **room_list)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (g_lem.start == 0 || g_lem.end == 0)
		time_to_exit();
	if (line[i] == '-')
		time_to_exit();
	while (line[i])
	{
		if (line[i] == '-' && line[i + 1] == '\0')
			time_to_exit();
		i++;
	}
	if (!g_lem.names)
		create_net_names(room_list);
	if (!g_lem.net)
		create_net(room_list);
	check_link_name(line, room_list);
}
