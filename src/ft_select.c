/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:26:52 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:15:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	lookup(t_display *display, const char *key)
{
	int	i;

	i = 0;
	while (i < display->argc)
	{
		if (display->argv[i][0] == key[0])
		{
			display->cursor = i;
			return ;
		}
		i++;
	}
}

void	ft_select(t_display *display)
{
	char	buf[1024];

	while (1)
	{
		redisplay(display);
		ft_bzero(buf, 1024);
		if (read(STDIN_FILENO, buf, 1024) <= 0)
			fatal("read error");
		if (ft_strequ(buf, "\012"))
			return ;
		keystroke(display, buf);
	}
}
