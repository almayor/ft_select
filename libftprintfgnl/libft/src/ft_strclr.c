/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:38:26 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:51:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets each character of a string to 0.
** @param s The string that needs to be cleared.
*/

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	ft_memset(s, 0, ft_strlen(s));
}
