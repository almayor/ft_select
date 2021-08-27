/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:37:14 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:57:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replicates behaviour of `memcpy` from `libc`.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	c1;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == c1)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
