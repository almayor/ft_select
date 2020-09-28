/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_maxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:13:00 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 23:13:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

size_t	tab_maxlen(char **t)
{
	size_t	maxlen;
	size_t	i;

	maxlen = 0;
	i = 0;
	while (t[i])
	{
		if (ft_strlen(t[i]) > maxlen)
			maxlen = ft_strlen(t[i]);
		i++;
	}
	return (maxlen);
}
