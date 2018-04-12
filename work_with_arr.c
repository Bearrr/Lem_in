/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:40:46 by ireva             #+#    #+#             */
/*   Updated: 2017/10/25 19:23:59 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_best_arr(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_lem.best_arr_size = 0;
	while (g_lem.temp_way_arr[j] != NULL)
		j++;
	g_lem.best_way_arr = (char **)malloc(sizeof(char *) * g_lem.w_size + 1);
	g_lem.best_way_arr[g_lem.w_size] = NULL;
	while (i < j)
	{
		g_lem.best_way_arr[i] = ft_strnew(ft_strlen(g_lem.temp_way_arr[i]));
		ft_strcpy(g_lem.best_way_arr[i], g_lem.temp_way_arr[i]);
		i++;
		g_lem.best_arr_size++;
	}
}

void		create_b_way_arr(void)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!g_lem.best_way_arr)
		create_best_arr();
	else
	{
		while (g_lem.best_way_arr[i])
			i++;
		while (g_lem.temp_way_arr[k])
			k++;
		if (i > k)
			create_best_arr();
	}
}

void		cr_temp_arr(int j)
{
	int		i;

	i = 0;
	while (g_lem.temp_way_arr[i] != NULL)
		i++;
	g_lem.temp_way_arr[i] = ft_strnew(ft_strlen(g_lem.names[i]));
	ft_strcpy(g_lem.temp_way_arr[i], g_lem.names[j]);
}

void		delete_last_room(void)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (g_lem.temp_way_arr[k])
		k++;
	k = 0;
	while (g_lem.temp_way_arr[i])
	{
		if (g_lem.temp_way_arr[i + 1] == '\0')
		{
			ft_strdel(&g_lem.temp_way_arr[i]);
			break ;
		}
		i++;
	}
}

void		check_way(int j)
{
	int		i;

	i = 0;
	g_lem.way[g_lem.w_start] = 1;
	cr_temp_arr(j);
	if (g_lem.way[g_lem.w_end] == 1)
	{
		create_b_way_arr();
		return ;
	}
	while (g_lem.w_size > i)
	{
		if (g_lem.net[j][i] == 1 && g_lem.way[i] == 0)
		{
			g_lem.way[i] = 1;
			check_way(i);
			delete_last_room();
			g_lem.way[i] = 0;
		}
		i++;
	}
}
