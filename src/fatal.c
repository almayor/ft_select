/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:03:57 by unite             #+#    #+#             */
/*   Updated: 2020/09/29 11:37:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	fatal(const char *mes)
{
	set_terminal(RESET);
	if (mes)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", "ft_select", mes);
	exit(errno);
}
