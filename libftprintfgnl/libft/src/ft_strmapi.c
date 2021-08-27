/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:46:53 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 03:22:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Maps a function to characters of a string and their indices
** Applies the function `f` to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with `malloc`) resulting from the successive
** applications of `f`.
** @param s The string to map.
** @param f The function to apply to each character and its index of `s`.
** @return	The “fresh” string created from the successive applications of f,
**			or `NULL` if allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_new = ft_strdup(s);
	if (!s_new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_new[i] = f(i, s[i]);
		i++;
	}
	return (s_new);
}
