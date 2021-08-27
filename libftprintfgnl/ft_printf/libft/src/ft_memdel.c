/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:30:56 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:56:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Frees memory where a pointer points to and sets the pointer to `NULL`.
** @param ap The pointer
*/

void	ft_memdel(void **ap)
{
	if (!ap || !(*ap))
		return ;
	free(*ap);
	*ap = 0;
}
