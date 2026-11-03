/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:02:29 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 15:51:54 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Copy this";
	char	dest[25] = "Original dest";
	char	*dest_return;
	
	printf("Before:\ndest = \"%s\" (at: %p)\nsrc = \"%s\" (at: %p)\n"
		"", dest, dest, (char*)src, src);
	dest_return = ft_memcpy(dest, src, 9);
	printf("After:\ndest = \"%s\" (at: %p)\nsrc = \"%s\" (at: %p)\n"
		"", dest, dest, (char*)src, src);
	printf("return value = \"%s\"\n", dest_return);
}*/
