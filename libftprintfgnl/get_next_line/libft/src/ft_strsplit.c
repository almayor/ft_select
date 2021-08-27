/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:31:18 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:43:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static const char	*search_delim(const char *s, char delim)
{
	while (*s && *s != delim)
		s++;
	return (s);
}

static const char	*search_not_delim(const char *s, char delim)
{
	while (*s && *s == delim)
		s++;
	return (s);
}

static size_t		count_words(const char *s, char delim)
{
	size_t	count;

	count = 0;
	s = search_not_delim(s, delim);
	while (*s)
	{
		count++;
		s = search_delim(s, delim);
		s = search_not_delim(s, delim);
	}
	return (count);
}

/*
** @brief Splits a string on whitespace characters
** @details Allocates (with `malloc`) and returns an array of “fresh”
** strings (all ending with ``'\0'``, including the array itself) obtained
** by splitting `s` using the character `c` as a delimiter.
** @par Example
** ``ft_strsplit("*hello*fellow***students*", ’*’)``
** returns the array ``["hello", "fellow", "students"]``.
** @param s The string to split.
** @param delim The delimiter character.
** @return	The array of “fresh” strings result of the split or `NULL` if
**			any of the allocations failed.
*/

char				**ft_strsplit(char const *s, char delim)
{
	char		**tab;
	const char	*start;
	const char	*end;
	size_t		wcount;
	size_t		i;

	wcount = count_words(s, delim);
	if (!(tab = ft_memalloc(sizeof(char *) * (wcount + 1))))
		return (NULL);
	i = 0;
	end = s;
	while (i < wcount)
	{
		start = search_not_delim(end, delim);
		end = search_delim(start, delim);
		if (!(tab[i] = ft_strndup(start, end - start)))
		{
			free_tab(tab);
			return (NULL);
		}
		i++;
	}
	tab[i++] = NULL;
	return (tab);
}
