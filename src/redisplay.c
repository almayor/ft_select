/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:01:36 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 10:03:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	check_size(t_display *display)
{
	struct winsize		win;

	if (ioctl(3, TIOCGWINSZ, &win))
		fatal("failed to get window size");
	if (win.ws_col <= display->colwidth || win.ws_row == 0)
	{
		tputs(tgetstr("bl", NULL), 1, &tputchar);
		tputs(tgetstr("mr", NULL), 1, &tputchar);
		ft_dprintf(3, "Window too small.\n");
		tputs(tgetstr("me", NULL), 1, &tputchar);
		return (1);
	}
	return (0);
}

static void	reposition(t_display *display)
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

static void	reformat(t_display *display)
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

static void	redisplay_entry(int i, t_display *display)
{
	if (i == display->cursor)
		tputs(tgetstr("us", NULL), 1, &tputchar);
	if (display->selected[i])
		tputs(tgetstr("mr", NULL), 1, &tputchar);
	ft_dprintf(3, "%s", display->argv[i]);
	if (i == display->cursor)
		tputs(tgetstr("ue", NULL), 1, &tputchar);
	if (display->selected[i])
		tputs(tgetstr("me", NULL), 1, &tputchar);
	ft_dprintf(3, "%*s",
				display->colwidth - 1 - ft_strlen(display->argv[i]), "");
}

static void	redisplay_row(int irow, t_display *display)
{
	int	i;
	int	icol;

	icol = 0;
	while (icol < display->ncols)
	{
		i = icol * display->nrows + irow;
		if (i >= display->argc)
			break ;
		if (icol != 0)
			tputchar(' ');
		redisplay_entry(i, display);
		icol++;
	}
}

void		redisplay(t_display *display)
{
	static t_display	*display_bkup;
	int					irow;

	if (display == NULL)
		display = display_bkup;
	else
		display_bkup = display;
	tputs(tgetstr("cl", NULL), 1, &tputchar);
	if (check_size(display))
		return ;
	reformat(display);
	reposition(display);
	irow = display->window_toprow;
	while (1)
	{
		redisplay_row(irow, display);
		irow++;
		if (irow == display->nrows ||
			irow - display->window_toprow > display->window_height - 1)
			break ;
		tputchar('\n');
	}
}