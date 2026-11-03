/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:34:07 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 20:26:27 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_memset can be substituted with a static function here
//Total number of functions (including above): 2

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	void	*s;
	int		i;

	s = malloc(20);
	printf("Before:\n");
	i = 0;
	while (i < 20)
	{
		((char *)s)[i] = 1;
		printf("%d", ((char *)s)[i++]);
	}
	ft_bzero(s, 10);
	printf("\nAfter:\n");
	i = 0;
	while (i < 20)
		printf("%d", ((char *)s)[i++]);
	return (0);
}*/
