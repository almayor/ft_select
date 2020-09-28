/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 02:10:20 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 18:55:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		print_selection(t_display *display)
{
	int	first;
	int	i;

	first = 1;
	i = 0;
	while (i < display->argc)
	{
		if (display->selected[i])
		{
			ft_dprintf(STDOUT_FILENO, "%c%s",
				first ? 0 : ' ', display->argv[i]);
			first = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

static size_t	tab_maxlen(char **t)
{
	size_t	maxlen;
	size_t	i;

	maxlen = 0;
	i = 0;
	while (t[i])
	{
		if (ft_strlen(t[i]) > maxlen)
			maxlen = ft_strlen(t[i]);
		i++;
	}
	return (maxlen);
}

static void		init(t_display *display, int argc, char **argv)
{
	size_t		sig;

	if (getenv("TERM") == NULL)
		fatal("TERM environmental variable is not set");
	if (tgetent(NULL, getenv("TERM")) != 1)
		fatal("tgetent error");
	if (!(display->selected = ft_calloc(argc, sizeof(int))))
		fatal("malloc error");
	display->argc = argc - 1;
	display->argv = argv + 1;
	display->colwidth = (int)tab_maxlen(display->argv) + 1;
	display->window_toprow = 0;
	if (display->colwidth < MIN_COLWIDTH)
		display->colwidth = MIN_COLWIDTH;
	sig = 1;
	while (sig < 30)
	{
		if (sig != 9 && sig != 17)
			signal(sig, &signal_handler);
		sig++;
	}
}

static void		deinit(t_display *display)
{
	free(display->selected);
}

int 			main(int argc, char *argv[])
{
	t_display	display;

	if (argc < 2)
		fatal("usage: ./ft_select arg1 ...");
	init(&display, argc, argv);
	set_terminal(SET);
	ft_select(&display);
	set_terminal(RESET);
	print_selection(&display);
	deinit(&display);
}
