/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_net.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:20:10 by ireva             #+#    #+#             */
/*   Updated: 2017/10/25 19:33:21 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			create_nod(char *line, t_listz **room_list)
{
	t_listz		*ptr;
	t_listz		*temp;

	temp = *room_list;
	ptr = (t_listz *)malloc(sizeof(t_listz));
	ptr->name = ft_wordslenz(line, ' ');
	ptr->next = NULL;
	if (g_lem.start == 1)
	{
		ptr->start = 1;
		g_lem.start = 2;
	}
	if (g_lem.end == 1)
	{
		ptr->end = 1;
		g_lem.end = 2;
	}
	if (*room_list == NULL)
		*room_list = ptr;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
}

void			create_net(t_listz **room_list)
{
	t_listz		*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = *room_list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	g_lem.net = (char **)malloc(sizeof(char *) * i + 1);
	while (i > j)
	{
		g_lem.net[j] = ft_strnew(i - 1);
		j++;
	}
}

void			create_net_names(t_listz **room_list)
{
	t_listz		*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = *room_list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	g_lem.names = (char**)malloc(sizeof(char*) * i + 1);
	g_lem.w_size = i;
	g_lem.names[i] = NULL;
	wr_names(room_list);
}

void			wr_names(t_listz **room_list)
{
	t_listz		*temp;
	int			i;

	i = 0;
	temp = *room_list;
	while (temp)
	{
		g_lem.names[i] = ft_strnew(ft_strlen(temp->name));
		ft_strcpy(g_lem.names[i], temp->name);
		i++;
		temp = temp->next;
	}
}

void			if_room(char *line, t_listz **room_list)
{
	if (g_lem.temp_name != NULL)
		time_to_exit();
	if (line[0] == 'L')
		time_to_exit();
	is_valid_room(line);
	check_duplic(line, room_list);
	create_nod(line, room_list);
	if (g_lem.free_start == 1)
		free(line);
	if (g_lem.free_end == 1)
		free(line);
}
