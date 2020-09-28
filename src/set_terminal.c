/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:04:17 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 16:34:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_caps(int mode)
{
	if (mode == RESET)
	{
		tputs(tgetstr("te", NULL), 1, &ft_putchar);
		tputs(tgetstr("ve", NULL), 1, &ft_putchar);
		tputs(tgetstr("ke", NULL), 1, &ft_putchar);
	}
	else if (mode == SET)
	{
		tputs(tgetstr("vi", NULL), 1, &ft_putchar);
		tputs(tgetstr("ti", NULL), 1, &ft_putchar);
		tputs(tgetstr("ks", NULL), 1, &ft_putchar);
	}
}

void		set_terminal(int mode)
{
	static int				isset = 0;
	static struct termios	term_old;
	struct termios			term_new;

	set_caps(mode);
	if (mode == RESET)
	{
		if (isset && tcsetattr(STDIN_FILENO, TCSADRAIN, &term_old))
			fatal("tcsetattr error");
	}
	else if (mode == SET)
	{
		if (tcgetattr(STDIN_FILENO, &term_old) ||
			tcgetattr(STDIN_FILENO, &term_new))
			fatal("tcgetattr error");
		isset = 1;
		term_new.c_lflag &= ~(ICANON | ECHO);
		term_new.c_cc[VMIN] = 1;
		term_new.c_cc[VTIME] = 0;
		if (tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &term_new))
			fatal("tcsetattr error");
	}
}
