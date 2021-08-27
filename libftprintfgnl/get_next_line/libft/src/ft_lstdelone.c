/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:22 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 03:02:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Deletes one link of a list
** @details Takes as a parameter a link’s pointer address and frees the
** memory of the link’s content using the function `del` given as
** a parameter, then frees the link’s memory using `free`. The
** memory of next must not be freed under any circumstance.
** Finally, the pointer to the link that was just freed must be
** set to `NULL` (quite similar to the function `memdel`).
** @param alst The adress of a pointer to a link that needs to be freed.
** @param del The address of a function to apply to each link of a list.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;

	if (!alst || !(*alst) || !del || !(*del))
		return ;
	link = *alst;
	link->next = NULL;
	del(link->content, link->content_size);
	free(link);
	*alst = NULL;
}
