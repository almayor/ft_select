/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:53:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** Writes the first n characters of a string to a file descriptor.
** @param s The string, the characters of which to output.
** @param n The number of characters to output.
** @param fd The file descriptor.
** @remark If `s` contains less than `n` characters, behaviour is undefined.
*/

void	ft_putnstr_fd(char *s, size_t n, int fd)
{
	write(fd, s, n);
}
