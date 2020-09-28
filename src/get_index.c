/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:14:11 by unite             #+#    #+#             */
/*   Updated: 2020/09/28 23:17:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_index_right(int i, t_display *display)
{
	int	icol;
	int	irow;

	icol = i / display->nrows;
	irow = i - icol * display->nrows;
	if (display->ncols == 1)
		return (i);
	if (icol + 1 == display->ncols)
		return (irow);
	if (i + display->nrows >= display->argc)
		return (irow);
	else
		return (i + display->nrows);
}

int	get_index_left(int i, t_display *display)
{
	int	icol;
	int	irow;

	icol = i / display->nrows;
	irow = i - icol * display->nrows;
	if (display->ncols == 1)
		return (i);
	if (icol == 0 && display->ncols == 2 &&
		(display->ncols - 1) * display->nrows + irow >= display->argc)
		return (i);
	if (icol == 0 &&
		(display->ncols - 1) * display->nrows + irow >= display->argc)
		return ((display->ncols - 2) * display->nrows + irow);
	if (icol == 0)
		return ((display->ncols - 1) * display->nrows + irow);
	else
		return (i - display->nrows);
}

int	get_index_top(int i, t_display *display)
{
	// int	icol;
	// int	irow;

	// icol = i / display->nrows;
	// irow = i - icol * display->nrows;
	// if (display->nrows == 1)
	// 	return (i);
	// if (irow == 0 && icol + 1 == display->ncols)
	// 	return (display->argc - 1);
	// if (irow == 0)
	// 	return (i + display->nrows - 1);
	// else
	// 	return (i - 1);
	return (i == 0 ? display->argc - 1 : i - 1);
}

int	get_index_bottom(int i, t_display *display)
{
	// int	icol;
	// int	irow;

	// icol = i / display->nrows;
	// irow = i - icol * display->nrows;
	// if (display->nrows == 1)
	// 	return (i);
	// if (i == display->argc - 1)
	// 	return ((display->ncols - 1) * display->nrows);
	// if (irow + 1 == display->nrows)
	// 	return (icol * display->nrows);
	// else
	// 	return (i + 1);
	return (i == display->argc - 1 ? 0 : i + 1);
}
