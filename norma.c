/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 21:15:16 by ireva             #+#    #+#             */
/*   Updated: 2017/10/26 14:47:30 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_duplic(char *line, t_listz **room_list)
{
	t_listz	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != ' ')
		i++;
	temp = *room_list;
	while (temp)
	{
		while (temp->name[j])
			j++;
		if (i == j)
			if (ft_strncmp(temp->name, line, i) == 0)
				time_to_exit();
		j = 0;
		temp = temp->next;
	}
}

void		norma(t_listz **room_list, t_listz **end, int i)
{
	t_listz	*temp;

	temp = *room_list;
	while (temp->next != NULL)
	{
		temp->ants = -1;
		if (ft_strcmp(g_lem.best_way_arr[i], temp->name) == 0)
			(*end) = temp;
		if (temp->start == 1)
			temp->ants = g_lem.ants;
		temp = temp->next;
	}
	if (temp->start == 1)
		temp->ants = g_lem.ants;
	else
		temp->ants = -1;
	if ((*end) == NULL)
		(*end) = temp;
}

void		norm(t_listz **current)
{
	if ((*current)->start != 1)
		(*current)->ants = -1;
	if ((*current)->start == 1 && (*current)->ants != -1)
	{
		(*current)->ants = (*current)->ants - 1;
		if ((*current)->ants == 0)
			(*current)->ants = -1;
	}
}

void		writter(t_listz *next)
{
	write(1, "L", 1);
	ft_putnbr(next->ants);
	write(1, "-", 1);
	ft_putstr(next->name);
	write(1, " ", 1);
}
