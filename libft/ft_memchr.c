/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:16:57 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 13:34:46 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	size_t			i;

	s_cpy = (unsigned char *)s;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == c)
			return (&s_cpy[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*s = "Can you find the hidden char?";
	int			c = (int)'?';
	size_t		n = INT_MIN;

	printf("ft_memchr:\ns = %s c = %c\nreturn = %p\n"
			"", (char *)s, c, ft_memchr(s, c, n));
	printf("****\nmemchr:\ns = %s c = %c\nreturn = %p\n"
			"", (char *)s, c, memchr(s, c, n));
	return (0);
}*/
