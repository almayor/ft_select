/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:41:57 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:45:53 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Applies a function to characters of a string and their indices.
** @details Applies the function `f` to each character of the string passed
** as argument, and passing its index as first argument.
** Each character is passed by address to `f` to be modified if necessary.
** @param s The string to iterate.
** @param f The function to apply to each character of `s` and its index.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}
