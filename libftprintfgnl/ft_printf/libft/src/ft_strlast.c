/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 04:51:37 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:44:58 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the last characters (other than `NULL`-termination) of a string.
** @param str The string.
** @return The last character of the string, or `0` if it is empty.
*/

char	ft_strlast(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}
