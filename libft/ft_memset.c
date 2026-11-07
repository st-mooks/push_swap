/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:42:44 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 14:18:16 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	size_t			i;

	s_copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_copy[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	void	*s;
	int		c;
	size_t	t;
	size_t	i;

	s = malloc(21);
	c = 'a';
	t = 20;
	s = memset(s, c, t);
	((char *)s)[20] = '\0';
	printf("Before ft_memset:\n%s\n", (char *)s);
	c = 'b';
	t = 10;
	ft_memset(s, c, t);
	printf("After ft_memset:\n%s\n", (char *)s);
	c = 'a';
	ft_memset(s, c, t);
	printf("Before memset:\n%s\n", (char *)s);
	c = 'b';
	memset(s, c, t);
	printf("After memset:\n%s\n", (char *)s);
	return (0);
}*/
