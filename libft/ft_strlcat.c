/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:20:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:16:58 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (i < dst_size)
		return (size + src_size);
	i = 0;
	while (size > dst_size + i + 1 && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
/*
int	main(int argc, char *argv[])
{
	char	src[] = "This is a src string";
	char	dst[100] = "This is a dest string";
	char	src2[] = "This is a src string";
	char	dst2[100] = "This is a dest string";
	size_t	return_value;
	size_t	size;

	if (argc != 2)
	{
		printf("INVLAID INPUT. ENTER THE SIZE.\nEXITING\n");
		exit(EXIT_FAILURE);
	}
	size = ft_atoi(argv[1]);
	printf("ft_strlcat:\nBefore:\ndst: %s\nsrc: %s\n", dst, src);
	return_value = ft_strlcat(dst, src, size);
	printf("After:\ndst: %s\nsrc: %s\nreturn: %zu\n", dst, src, return_value);
	printf("******\nstrlcat:\nBefore:\ndst: %s\nsrc: %s\n", dst2, src2);
	return_value = strlcat(dst2, src2, size);
	printf("After:\ndst: %s\nsrc: %s\nreturn: %zu\n", dst2, src2, return_value);
	return (0);
}*/
