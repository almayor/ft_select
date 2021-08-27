/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:40:13 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 03:03:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Deletes all links in a list
** @details Takes as a parameter the address of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions `del` and `free`. Finally the pointer to
** the link that was just freed must be set to `NULL` (quite similar
** to the function `memdel`).
** @param alst The address of a pointer to the first link of a list that needs
** to be freed.
** @param del The address of a function to apply to each link of a list.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;
	t_list *new_head;

	if (!alst || !(*alst) || !del)
		return ;
	head = *alst;
	while (head)
	{
		new_head = head->next;
		del(head->content, head->content_size);
		free(head);
		head = new_head;
	}
	*alst = NULL;
}
