/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:38:31 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:14:28 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_lstlast can be substituted with a static function here
//Total number of functions (including above): 2

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
		ft_lstlast(*lst)->next = new;
}
/*
int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	lst1 = ft_lstnew("First");
	printf("First node pointer=%p\n", lst1);
	lst2 = ft_lstnew("Second");
	printf("second node pointer=%p\n", lst2);
	lst3 = ft_lstnew("Third");
	printf("Third node pointer=%p\n", lst3);
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst2, lst3);
	printf("***\nRunning: ft_lstadd_back(&lst1, lst2)\n"
			"Running: ft_lstadd_back(&lst2, lst3)\n***\n");
	printf("List head=%p with content=%s"
			"\n", lst1, (char *)lst1->content);
	printf("Last element in linked list=%p"
			" with content=%s"
			"", ft_lstlast(lst2), (char *)ft_lstlast(lst2)->content);
	return (0);
}*/
