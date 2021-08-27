/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:49:32 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:49:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Checks that two strings are identical
** @details Performs lexicographical comparison between `s1` and `s2`.
** @param s1 The first string to be compared.
** @param s2 The second string to be compared.
** @return `1`if the strings are identical or `0` otherwise.
*/

int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
