/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:49:16 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 12:57:33 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*lst1;
	
	lst1 = ft_lstnew(ft_strdup("original"));
	printf("%p: %s\n", lst1, (char *)lst1->content);
	ft_lstdelone(lst1, free);
	return (0);
}*/
