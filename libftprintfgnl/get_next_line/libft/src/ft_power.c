/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:09:37 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:55:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** Raises a number to a given power.
** @param num The base.
** @param exponent The exponent.
** @return The result or `0` if integer overflow occurred.
*/

int	ft_power(int num, unsigned int exponent)
{
	long long result;

	result = 1;
	while (exponent-- > 0)
		result *= num;
	if (result > INT_MAX)
		return (0);
	else
		return ((int)result);
}
