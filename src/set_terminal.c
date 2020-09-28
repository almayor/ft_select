/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:04:17 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 23:10:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_caps(int mode)
{
	if (mode == RESET)
	{
		tputs(tgetstr("te", NULL), 1, &tputchar);
		tputs(tgetstr("ve", NULL), 1, &tputchar);
		tputs(tgetstr("ke", NULL), 1, &tputchar);
	}
	else if (mode == SET)
	{
		tputs(tgetstr("vi", NULL), 1, &tputchar);
		tputs(tgetstr("ti", NULL), 1, &tputchar);
		tputs(tgetstr("ks", NULL), 1, &tputchar);
	}
}

void		set_terminal(int mode)
{
	static int				isset = 0;
	static struct termios	term_old;
	struct termios			term_new;

	if (mode == RESET)
	{
		if (isset && tcsetattr(3, TCSADRAIN, &term_old))
			fatal("tcsetattr error");
	}
	else if (mode == SET)
	{
		if (tcgetattr(3, &term_old) ||
			tcgetattr(3, &term_new))
			fatal("tcgetattr error");
		isset = 1;
		term_new.c_lflag &= ~(ICANON | ECHO);
		term_new.c_cc[VMIN] = 1;
		term_new.c_cc[VTIME] = 0;
		if (tcsetattr(3, TCSANOW | TCSAFLUSH, &term_new))
			fatal("tcsetattr error");
	}
	set_caps(mode);
}
