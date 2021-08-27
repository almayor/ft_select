/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:55:46 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:54:02 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes an integer to the standard output.
** @param n The integer to output.
*/

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
