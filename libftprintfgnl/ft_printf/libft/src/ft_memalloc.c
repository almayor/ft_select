/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:27:33 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 03:00:08 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates memory of a given size and initializes it to 0.
** @param size The size of the memory that needs to be allocated.
** @return The allocated memory area, or `NULL` if allocation fails.
** @see ft_calloc
*/

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
