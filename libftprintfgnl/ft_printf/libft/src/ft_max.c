/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 02:01:56 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:59:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the maximum of two integer arguments.
** @note This function is only needed, since "The Norme" (the code standard
** at School 42) forbids the use of parametrized macros.
** @param[in] a The first integer to compare.
** @param[in] b The second integer to compare.
** @return The larger of the two integers.
*/

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}
