/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:34:13 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:51:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of occurrences of a character in a string.
** @param str The string in which to search.
** @param c The character for which to search.
** @return The number of occurences.
*/

int		ft_strcchr(char const *str, char c)
{
	int count;

	count = 0;
	if (!str || !c)
		return (-1);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
