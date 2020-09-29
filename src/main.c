/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 02:10:20 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 09:56:28 by unite            ###   ########.fr       */
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
			if (!first)
				ft_putchar(' ');
			ft_dprintf(STDOUT_FILENO, "%s", display->argv[i]);
			first = 0;
		}
		i++;
	}
	if (!first)
		ft_putchar('\n');
}

static void		init(t_display *display, int argc, char **argv)
{
	if (getenv("TERM") == NULL)
		fatal("TERM environmental variable is not set");
	if (tgetent(NULL, getenv("TERM")) != 1)
		fatal("tgetent error");
	if (!(display->selected = ft_calloc(argc, sizeof(int))))
		fatal("malloc error");
	if ((display->fd = open("/dev/tty", O_RDWR)) < 0)
		fatal("failed to open /dev/tty");
	display->argc = argc - 1;
	display->argv = argv + 1;
	display->colwidth = (int)tab_maxlen(display->argv) + 1;
	display->window_toprow = 0;
	if (display->colwidth < MIN_COLWIDTH)
		display->colwidth = MIN_COLWIDTH;
}

static void		deinit(t_display *display)
{
	free(display->selected);
	close(display->fd);
}

int 			main(int argc, char *argv[])
{
	t_display	display;

	if (argc < 2)
		fatal("usage: ./ft_select arg1 ...");
	init(&display, argc, argv);
	set_signals();
	set_terminal(SET);
	ft_select(&display);
	set_terminal(RESET);
	print_selection(&display);
	deinit(&display);
}
