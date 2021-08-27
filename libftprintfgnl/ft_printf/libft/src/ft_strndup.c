/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:41:24 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:43:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Makes a new string and copies up to `len` characters to it
** @details Allocate sufficient memory for a string of `len` characters,
** do the copy of `len` characters, `NULL` terminate the string,
** and return a pointer to it. The pointer may
** subsequently be used as an argument to the function `free`.
** @param s1 String to be copied from.
** @param len Number of characters to copy.
** @return	String of length `len` with copied characters or `NULL` if
**			allocation failed.
** @remark If `s1` contains less than `len` characters, behaviour is undefined.
*/

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
