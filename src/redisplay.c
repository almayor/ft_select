/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:01:36 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 18:26:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	reposition(t_display *display)
{
	int	cursor_icol;
	int	cursor_irow;

	cursor_icol = display->cursor / display->nrows;
	cursor_irow = display->cursor - cursor_icol * display->nrows;
	if (cursor_irow < display->window_toprow ||
		cursor_irow - display->window_toprow > display->window_height)
		display->window_toprow = cursor_irow;
}

static void	reformat(t_display *display)
{
	struct winsize		win;
	int					max_on_screen;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &win))
		fatal("failed to get window size");
	if (win.ws_col == 0 || win.ws_row == 0)
		fatal("printing to an invalid terminal");
	display->window_height = win.ws_row;
	max_on_screen = win.ws_col / display->colwidth * win.ws_row;
	if (display->argc > max_on_screen)
		display->ncols = win.ws_col / display->colwidth;
	else
	{
		display->ncols = display->argc / win.ws_row;
		display->ncols += display->argc % win.ws_row > 0 ? 1 : 0;
	}
	display->nrows = display->argc / display->ncols;
	display->nrows += display->argc % display->ncols > 0 ? 1 : 0;
}

static void	redisplay_entry(int i, t_display *display)
{
	if (i == display->cursor)
		tputs(tgetstr("us", NULL), 1, &ft_putchar);
	if (display->selected[i])
		tputs(tgetstr("mr", NULL), 1, &ft_putchar);
	ft_printf("%s", display->argv[i]);
	if (i == display->cursor)
		tputs(tgetstr("ue", NULL), 1, &ft_putchar);
	if (display->selected[i])
		tputs(tgetstr("me", NULL), 1, &ft_putchar);
	ft_printf("%*s", display->colwidth - ft_strlen(display->argv[i]), "");
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
			ft_putchar(' ');
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
	reformat(display);
	reposition(display);
	tputs(tgetstr("cl", NULL), 1, &ft_putchar);
	irow = display->window_toprow;
	while (1)
	{
		redisplay_row(irow, display);
		irow++;
		if (irow == display->nrows ||
			irow - display->window_toprow > display->window_height - 1)
			break ;
		ft_putchar('\n');
	}
}