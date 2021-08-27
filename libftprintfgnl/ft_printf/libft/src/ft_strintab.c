/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:26:15 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:48:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** @brief Checks if a string is in a tab
** @details Performs lexicographical comparison between a given string and
** strings contained in a `NULL`-terminated tab.
** @param str The string to search for.
** @param tab The `NULL`-terminated tab to search in.
** @return `1` if the tab contains the string or `0` otherwise.
*/

int	ft_strintab(const char *str, char *const tab[])
{
	while (*tab)
	{
		if (ft_strequ(str, *tab))
			return (1);
		tab++;
	}
	return (0);
}
