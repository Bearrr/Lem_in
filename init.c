/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:30:06 by ireva             #+#    #+#             */
/*   Updated: 2017/10/25 18:48:46 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			way_s_e(t_listz **room_list)
{
	int			i;
	t_listz		*temp;

	g_lem.nod_count = g_lem.w_size;
	i = 0;
	temp = *room_list;
	while (temp)
	{
		if (temp->start == 1)
			g_lem.w_start = i;
		if (temp->end == 1)
			g_lem.w_end = i;
		i++;
		temp = temp->next;
	}
}

void			init(void)
{
	int			i;

	i = 0;
	g_lem.way = (int *)malloc(sizeof(int) * g_lem.w_size);
	while (i < (g_lem.w_size))
	{
		g_lem.way[i] = 0;
		i++;
	}
	g_lem.temp_way_arr = (char **)malloc(sizeof(char *) * g_lem.w_size + 1);
	i = 0;
	while (i < g_lem.w_size + 1)
	{
		g_lem.temp_way_arr[i] = NULL;
		++i;
	}
}

void			init_ints(void)
{
	g_lem.ants = 0;
	g_lem.start = 0;
	g_lem.end = 0;
	g_lem.links = 0;
}

void			is_valid_room(char *line)
{
	int			i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i] != ' ')
	{
		if (line[i] >= '0' && line[i] <= '9')
			i++;
		else
			time_to_exit();
	}
	if (line[i] == ' ')
		i++;
	while (line[i] || line[i] != ' ')
	{
		if (line[i] >= '0' && line[i] <= '9')
			i++;
		else if (line[i] == '\0')
			break ;
		else
			time_to_exit();
	}
}
