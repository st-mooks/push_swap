/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:55:43 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:07:56 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main()
{
	char	dst[] = "dst to be replaced";
	char	src[] = "This is src";
	size_t	return_value;
	char    dst2[] = "dst to be replaced";
	size_t	size;

	size = 0;
	printf("ft_strlcat:\nBefore:\ndst: %s\nsrc: %s\n", dst, src);
	return_value = ft_strlcpy(dst, src, size);
	printf("After:\ndst: %s\nsrc: %s\nreturn: %zu\n", dst, src, return_value);
	printf("*****\nstrlcat:\nBefore:\ndst: %s\nsrc: %s\n", dst2, src);
	return_value = strlcpy(dst2, src, size);
	printf("After:\ndst: %s\nsrc: %s\nreturn: %zu\n", dst2, src, return_value);
	return (0);
}*/
