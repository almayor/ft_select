/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:51:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:52:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	scroll_to_word(char **s)
{
	while (**s)
	{
		if (ft_isalnum(**s))
			return (1);
		*s += 1;
	}
	return (0);
}

static void	capitalize_word(char **s)
{
	**s = ft_toupper(**s);
	*s += 1;
	while (ft_isalnum(**s))
	{
		**s = ft_tolower(**s);
		*s += 1;
	}
}

/*
** @brief Capitalizes all words in a string
** @details Capitalizes all words (defined as stretches of alpha-numeric
** characters) in a `NULL`-terminated string and writes them to a
** newly allocated string.
** @par Example
** ``ft_strcapitalize("My word IS 42about%8THEM")``
** returns ``"My Word Is 42about%8them")``
** @param s1 The string to capitalize.
** @return	A duplicate of `str` in which all words have been capitalized,
**			or `NULL` if allocation fails.
*/

char		*ft_strcapitalize(const char *s1)
{
	char	*s2;

	if (!s1 || !(s2 = ft_strdup(s1)))
		return (0);
	while (scroll_to_word(&s2))
		capitalize_word(&s2);
	return (s2);
}
