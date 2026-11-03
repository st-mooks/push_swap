/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:27:23 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 13:18:02 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	lst1 = ft_lstnew("original");
	printf("orignal element pointer=%p\n", lst1);
	lst2 = ft_lstnew("second");
	printf("second element pointer=%p\n", lst2);
	lst3 = ft_lstnew("newest");
	printf("newest element pointer -to become last-=%p\n", lst3);
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst2, lst3);
	printf("Last element in linked list=%p with content=%s"
			"", ft_lstlast(lst1), (char *)ft_lstlast(lst1)->content);
	return (0);
}*/
