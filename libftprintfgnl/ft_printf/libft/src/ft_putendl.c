/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:51:34 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:54:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a string to the standard output followed by a newline.
** @param s The string to output.
*/

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
