/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:15:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 22:02:47 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	lst1 = ft_lstnew("original");
	lst2 = ft_lstnew("second");
	lst3 = ft_lstnew("newest)");
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst2, lst3);
	printf("Linked list size (ls1) = %u\n", ft_lstsize(lst1));
	return (0);
}*/
