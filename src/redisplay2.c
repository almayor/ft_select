/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:16:29 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:33:27 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	reposition(t_display *display)
{
	int	cursor_icol;
	int	cursor_irow;

	cursor_icol = display->cursor / display->nrows;
	cursor_irow = display->cursor - cursor_icol * display->nrows;
	if (cursor_irow < display->window_toprow)
		display->window_toprow = cursor_irow;
	if (cursor_irow - display->window_toprow == display->window_height)
		display->window_toprow++;
	if (cursor_irow - display->window_toprow > display->window_height)
		display->window_toprow = cursor_irow;
}

void	reformat(t_display *display)
{
	struct winsize		win;
	int					max_on_screen;

	if (ioctl(3, TIOCGWINSZ, &win))
		fatal("failed to get window size");
	display->window_height = win.ws_row;
	max_on_screen = win.ws_col / display->colwidth * win.ws_row;
	if (display->argc > max_on_screen)
	{
		display->ncols = win.ws_col / display->colwidth;
		display->nrows = display->argc / display->ncols;
		display->nrows += display->argc % display->ncols > 0 ? 1 : 0;
	}
	else
	{
		display->ncols = display->argc / win.ws_row;
		display->ncols += display->argc % win.ws_row > 0 ? 1 : 0;
		display->nrows = display->argc > display->window_height ?
							display->window_height : display->argc;
	}
}
