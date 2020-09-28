/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroke.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:05:59 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 18:19:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	keystroke_del(t_display *display)
{
	int	i;

	i = display->cursor;
	while (i < display->argc - 1)
	{
		display->argv[i] = display->argv[i + 1];
		display->selected[i] = display->selected[i + 1];
		i++;
	}
	display->argc--;
	if (display->argc == 0)
		fatal(NULL);
}

static void	keystroke_space(t_display *display)
{
	display->selected[display->cursor] = !display->selected[display->cursor];
	display->cursor = get_index_bottom(display->cursor, display);
}

static void	keystroke_down(t_display *display)
{
	int					icol;
	int					irow;

	display->cursor = get_index_bottom(display->cursor, display);
	icol = display->cursor / display->nrows;
	irow = display->cursor - icol * display->nrows;
	if (irow - display->window_toprow >= display->window_height)
		display->window_toprow++;
	else if (irow < display->window_toprow)
	{
		display->window_toprow = 0;
		tputs(tgetstr("bl", NULL), 1, &ft_putchar);
	}
}

static void	keystroke_up(t_display *display)
{
	int	icol;
	int	irow;

	display->cursor = get_index_top(display->cursor, display);
	icol = display->cursor / display->nrows;
	irow = display->cursor - icol * display->nrows;
	if (irow < display->window_toprow)
		display->window_toprow--;
	else if (irow - display->window_toprow >= display->window_height)
	{
		display->window_toprow = display->nrows - display->window_height;
		tputs(tgetstr("bl", NULL), 1, &ft_putchar);
	}
}

static void	lookup(t_display *display, const char *key)
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

void		keystroke(t_display *display, const char *key)
{
	if (ft_strequ(key, "\177"))
		keystroke_del(display);
	else if (ft_strequ(key, " "))
		keystroke_space(display);
	else if (ft_strequ(key, tgetstr("ku", NULL)))
		keystroke_up(display);
	else if (ft_strequ(key, tgetstr("kd", NULL)))
		keystroke_down(display);
	else if (ft_strequ(key, tgetstr("kl", NULL)))
		display->cursor = get_index_left(display->cursor, display);
	else if (ft_strequ(key, tgetstr("kr", NULL)))
		display->cursor = get_index_right(display->cursor, display);
	else if (ft_strequ(key, "\033") || ft_strequ(key, "q"))
		fatal(NULL);
	else
		lookup(display, key);
}
