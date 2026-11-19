/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:24:39 by mbadarin          #+#    #+#             */
/*   Updated: 2026/09/29 12:14:28 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
/*
int	main(void)
{
	t_list	*linked_list;

	linked_list = ft_lstnew("This is a the content of the first element");
	printf("linked_list content=%s\nlinked_lest next==NULL: %d"
			"", (char *)linked_list->content, linked_list->next == NULL);
}*/
