/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:04:31 by ireva             #+#    #+#             */
/*   Updated: 2016/12/08 13:49:00 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freedom(t_list **alst)
{
	if (!(*alst))
		return ;
	if ((*alst)->next)
	{
		ft_freedom(&(*alst)->next);
		free(*alst);
		*alst = NULL;
	}
}
