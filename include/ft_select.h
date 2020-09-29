/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 02:13:53 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:39:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include <errno.h>
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>

# include "libftprintfgnl.h"

# ifndef SIGWINCH
#  define SIGWINCH	28
# endif

# ifndef NSIG
#  define NSIG		64
# endif

# define SET		1
# define RESET		0

# define MIN_COLWIDTH	8

typedef struct	s_display
{
	int		fd;
	int		argc;
	char	**argv;
	int		*selected;
	int		cursor;
	int		colwidth;
	int		nrows;
	int		ncols;
	int		window_toprow;
	int		window_height;
}				t_display;

/*
** select
*/

void			ft_select(t_display *display);
void			lookup(t_display *display, const char *key);
void			keystroke(t_display *display, const char *key);

/*
** control
*/

void			set_terminal(int mode);
void			set_signals(void);
void			fatal(const char *mes);

/*
** display
*/

void			reformat(t_display *display);
void			reposition(t_display *display);
void			redisplay(t_display *display);

/*
** accessory
*/

int				get_index_bottom(int i, t_display *display);
int				get_index_left(int i, t_display *display);
int				get_index_right(int i, t_display *display);
int				get_index_top(int i, t_display *display);

/*
** utils
*/

size_t			tab_maxlen(char **t);
int				tputchar(int c);

#endif
