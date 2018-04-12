/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:11:45 by ireva             #+#    #+#             */
/*   Updated: 2017/10/26 16:17:15 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				if_alpha(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			return (1);
		if (line[i] >= 'a' && line[i] <= 'z')
			return (1);
		i++;
	}
	return (0);
}

int				count_spaces(char *line)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int				count_defis(char *line)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	return (j);
}

void			time_to_exit(void)
{
	write(1, "ERROR\n", 6);
	exit(2);
}

char			*ft_wordslenz(char *s, char c)
{
	char		*arr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s && !c)
		return (NULL);
	while (s[i] != c)
		i++;
	i--;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	arr[i + 1] = '\0';
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	return (arr);
}
