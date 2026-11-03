/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:48:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/09/29 14:06:14 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const void	*s1 = "What is the difference?";
	const void	*s2 = "What is the difference? Here it is!";
	size_t		n = 25;
	
	printf("ft_memcmp:\ns1 = %s\ns2 = %s\nn = %zu\nreturn = "
			"%d", (char *)s1, (char *)s2, n, ft_memcmp(s1, s2, n));
	printf("\n****\nmemcmp:\ns1 = %s\ns2 = %s\nn = %zu\nreturn = "
			"%d", (char *)s1, (char *)s2, n, memcmp(s1, s2, n));
	return (0);
}*/
