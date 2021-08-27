/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:43:42 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 03:22:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Maps a function to characters of a string
** @details Applies the function `f` to each character of the string given
** as argument to create a “fresh” new string (with `malloc`)
** resulting from the successive applications of `f`.
** @param s The string to map.
** @param f The function to apply to each character of `s`.
** @return	The “fresh” string created from the successive applications of `f`,
**			or `NULL` if allocation fails.
*/

char	*ft_strmap(char const *s, char (*f)(char))
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
		s_new[i] = f(s[i]);
		i++;
	}
	return (s_new);
}
