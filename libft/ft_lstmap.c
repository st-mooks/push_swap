/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:50:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 13:15:37 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_lstclear can be substituted with a static function here
//ft_lstdelone can be substituted with a static function here
//ft_lstnew can be substituted with a static function here
//Total number of functions (including above): 5

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cpy;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	lst_cpy = ft_lstnew(f(lst->content));
	if (!lst_cpy)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst_cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_cpy, node);
		lst = lst->next;
	}
	return (lst_cpy);
}
/*
void	*first_two(void *content)
{
	char	*str;
	int		i;

	str = malloc(3 * sizeof(char));
	i = 0;
	while (i < 2)
	{
		str[i] = ((char *)content)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst_cpy;
	t_list	*ptr;
	int		i;

	lst1 = ft_lstnew(ft_strdup("First"));
	lst2 = ft_lstnew(ft_strdup("Second"));
	lst3 = ft_lstnew(ft_strdup("Third"));
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst2, lst3);
	lst_cpy = ft_lstmap(lst1, first_two, free);
	i = 0;
	ptr = lst1;
    while (ptr)
	{
		printf("Original list node no. %d content:\"%s\", next:%p, "
				"location:%p\n", i++, (char *)ptr->content, ptr->next, ptr);
		ptr = ptr->next;
	}
	i = 0;
	ptr = lst_cpy;
	while (ptr)
	{
		printf("New list node no. %d content:\"%s\", next:%p, "
				"location:%p\n", i++, (char *)ptr->content, ptr->next, ptr);
		ptr = ptr->next;
	}
	printf("lst_cpy size:%u", ft_lstsize(lst_cpy));
	ft_lstclear(&lst1, free);
	ft_lstclear(&lst_cpy, free);
	return (0);
}*/
