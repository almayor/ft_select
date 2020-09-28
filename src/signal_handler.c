/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:04:53 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 19:20:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGSEGV)
		fatal("You found a segfault! Good for you! 🤩💪");
	else if (sig == SIGTSTP)
	{
		set_terminal(RESET);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGCONT, &signal_handler);
		kill(0, SIGTSTP);
	}
	else if (sig == SIGCONT)
	{
		set_terminal(SET);
		signal(SIGCONT, SIG_DFL);
		signal(SIGTSTP, &signal_handler);
		redisplay(NULL);
		kill(0, SIGCONT);
	}
	else if (sig == SIGWINCH)
		redisplay(NULL);
	else
		fatal(NULL);
}
