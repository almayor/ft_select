/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:04:34 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:56:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replicates behaviour of `memset` from `libc`.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	c1;

	s = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (len-- > 0)
	{
		*s = c1;
		s++;
	}
	return (b);
}
