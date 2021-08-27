/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:51:03 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:42:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Checks that two strings are unequal
** @details Lexicographical comparison between `s1` and `s2`
** up to`n` characters or until a ``'\0'`` is reached.
** @param s1 The first string to be compared.
** @param s2 The second string to be compared.
** @param n The maximum number of characters to be compared.
** @return `1` or `0` according to if the 2 strings are identical or not.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while ((*s1 || *s2) && n-- > 0)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
