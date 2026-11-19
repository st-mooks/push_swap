/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:35:43 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 11:34:10 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_memset can be substituted with a static function here
//ft_bzero can be substituted with  a static function here
//Total number of functions (including above): 4

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc_arr;

	if (size * nmemb == 0)
		alloc_arr = malloc(0);
	else if (SIZE_MAX / size < nmemb)
		return (NULL);
	else
	{
		alloc_arr = malloc(nmemb * size);
		if (!alloc_arr)
			return (NULL);
		ft_bzero(alloc_arr, nmemb * size);
	}
	return (alloc_arr);
}
/*
int	main(void)
{
	int		*ft_calloc_return;
	int		*calloc_return;
	size_t	nmemb;
	size_t	size;

	nmemb = SIZE_MAX;
	size = 2;
	ft_calloc_return = ft_calloc(nmemb, size);
	calloc_return = calloc(nmemb, size);
	if (ft_calloc_return)
		printf("ft_calloc:\ncontents of ft_calloc[0] = %d\n"
				"", *ft_calloc_return);
	else
		printf("ft_calloc_return == NULL: %d\n", ft_calloc_return == NULL);
	if (calloc_return)
		printf("calloc:\ncontents of calloc[0] = %d\n"
				"", *calloc_return);
	else
		printf("calloc_return == NULL: %d\n", calloc_return == NULL);
	free(ft_calloc_return);
	printf("ft_calloc_return successfully freed!\n");
	free(calloc_return);
	printf("calloc_return successfully freed!\n");
	return (0);
}*/
