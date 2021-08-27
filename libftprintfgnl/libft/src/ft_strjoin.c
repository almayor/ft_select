/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:53:04 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:45:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Joins two strings
** @details Allocates (with `malloc`) and returns a “fresh” string ending
** with ``'\0'``, result of the concatenation of `s1` and `s2`. If
** the allocation fails the function returns `NULL`.
** @param s1 The prefix string.
** @param s2 The suffix string.
** @return The “fresh” string result of the concatenation of the 2 strings.
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_joined;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (char *)s2;
	else if (!s2)
		return (char *)s1;
	if (!(s_joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	s_joined = ft_strcpy(s_joined, s1);
	s_joined = ft_strcat(s_joined, s2);
	return (s_joined);
}
