/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:01:36 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:38:10 by unite            ###   ########.fr       */
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
