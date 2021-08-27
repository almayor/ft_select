/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:33:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:42:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Allocates a fresh string
** @details Allocates (with `malloc`) and returns a “fresh” string ending with
** ``'\0'``. Each character of the string is initialized at ``'\0'``.
** @param size The size of the string to be allocated.
** @return	The string allocated and initialized to `0` or `NULL` if allocation
**			failed.
*/

char	*ft_strnew(size_t size)
{
	if (size + 1 < size)
		return (NULL);
	return (ft_memalloc(sizeof(char) * (size + 1)));
}
