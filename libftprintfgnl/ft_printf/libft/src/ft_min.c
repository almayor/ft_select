/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 02:02:23 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:55:58 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the minimum of two integer arguments.
** @note This function is only needed, because the "Norme" (the code standard
** at School 42) forbids the use of parametrized macros.
** @param[in] a The first integer to compare.
** @param[in] b The second integer to compare.
** @return The smaller of the two integers.
*/

int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}
