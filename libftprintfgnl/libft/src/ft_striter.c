/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:39:55 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:46:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Applies a function to characters of a string
** @details Applies the function `f` to each character of the string passed as
** argument. Each character is passed by address to `f` to be modified
** if necessary.
** @param s The string to iterate.
** @param f The function to apply to each character of `s`.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}
