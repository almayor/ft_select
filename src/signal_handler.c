/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:04:53 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 16:41:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGSEGV)
		fatal("You found a segfault! Good for you! 🤩💪");
	if (sig == SIGWINCH)
		redisplay(NULL);
	else
		fatal(NULL);
}
