/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 02:10:20 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:38:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char		*escape_spaces(const char *s)
{
	size_t	nspaces;
	size_t	i;
	size_t	j;
	size_t	len;
	char	*s1;

	nspaces = ft_strcchr(s, ' ');
	len = ft_strlen(s);
	s1 = ft_calloc(len + nspaces + 1, sizeof(char));
	i = 0;
	j = 0;
	while (i < len)
	{
		if (s[i] == ' ')
			s1[j++] = 92;
		s1[j] = s[i];
		++i;
		++j;
	}
	return s1;
}

static void		print_selection(t_display *display)
{
	int		first;
	int		i;
	char	*escaped_name;

	first = 1;
	i = 0;
	while (i < display->argc)
	{
		if (display->selected[i])
		{
			if (!first)
				ft_putchar(' ');
			escaped_name = escape_spaces(display->argv[i]);
			ft_dprintf(STDOUT_FILENO, "%s", escaped_name);
			free(escaped_name);
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

int				main(int argc, char *argv[])
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
