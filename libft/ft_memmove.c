/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:38:21 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 13:34:29 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//ft_memcpy can be substituted with  a static function here
//Total number of functions (including above): 2

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	offset;

	if ((uintptr_t)dest > (uintptr_t)src)
	{
		i = 0;
		while (i < n)
		{
			offset = n - i - 1;
			*((char *)dest + offset) = *((char *)src + offset);
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int	main(void)
{
	char	*dest;
	char	*src;
	char	*dest_return;
	char	*dest2;
	char	*src2;
	char    *dest_return2;
	char	*src3;
	char	*dest3;
	char	*dest_return3;
	int		offset;

	src = ft_strdup("Copy this text");
	src2 = ft_strdup("Copy this text");
	src3 = ft_strdup("Copy this text");
	offset = 5;
	dest = src + offset;
	dest2 = src2 + offset;
	dest3 = src3 + offset;
	printf("***ft_memmove***\n");
	printf("Before:\ndest:\"%s\"\nsrc:\"%s\"\n", dest, src);
	dest_return = ft_memmove(dest, src, ft_strlen(src) - offset);
	printf("After:\ndest:\"%s\"\nsrc:\"%s\"\n", dest, src);
	printf("dest_return:\"%s\"\n", dest_return);
	printf("***ft_memcpy***\n");
	printf("Before:\ndest:\"%s\"\nsrc:\"%s\"\n", dest3, src3);
	dest_return3 = ft_memcpy(dest3, src3, ft_strlen(src3) - offset);
	printf("After:\ndest:\"%s\"\nsrc:\"%s\"\n", dest3, src3);
	printf("dest_return:\"%s\"\n", dest_return3);
	printf("***Original***\n");
	printf("Before:\ndest:\"%s\"\nsrc:\"%s\"\n", dest2, src2);
	dest_return2 = memmove(dest2, src2, ft_strlen(src2) - offset);
	printf("After:\ndest:\"%s\"\nsrc:\"%s\"\n", dest2, src2);
	printf("dest_return:\"%s\"\n", dest_return2);
	free(src);
	return (0);
}*/
