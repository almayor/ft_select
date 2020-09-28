/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:26:52 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 16:50:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
