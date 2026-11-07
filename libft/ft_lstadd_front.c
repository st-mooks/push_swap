/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:50:20 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/07 11:50:06 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*second;
	t_list	*new;

	lst = ft_lstnew("First");
	second = ft_lstnew("Second");
	new = ft_lstnew("Third");
	printf("BEFORE:\nhead pointer=%p\nsecond pointer=%p\n", lst, second);
	ft_lstadd_front(&lst, second);
	printf("ADDING SECOND:\nhead pointer=%p\nsecond.next=%p\n"
			"", lst, second->next);
	ft_lstadd_front(&lst, new);
	printf ("AFTER:\nhead pointer=%p\nnew.next=%p\n", lst, new->next);
	return (0);
}*/
