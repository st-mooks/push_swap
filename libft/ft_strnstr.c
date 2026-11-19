/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:44:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 20:55:50 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i + 1 <= len && big[i])
	{
		n = 0;
		while (i + n + 1 <= len && little[n])
		{
			if (big[i + n] == little[n])
			{
				n++;
				continue ;
			}
			break ;
		}
		if (n == ft_strlen((char *)little))
			return (&((char *)big)[i]);
		i++ ;
	}
	return (NULL);
}
/*
int	main(int argc, char *argv[])
{
	const char	*big;
	const char	*little;
	size_t		len;

	if (argc != 4)
	{
		printf("INVALID INPUT.\nVALID INPUT NO.: 3. I.E.: CHAR * CHAR * SIZE_T"
				"\nEXITNG\n");
		exit(EXIT_FAILURE);
	}
	big = argv[1];
	little = argv[2];
	len = (size_t)ft_atoi(argv[3]);
	printf("ft_strnstr:\nbig = %s\nlittle = %s\nlen = %zu\nreturn = %p"
			"\n",big, little, len, ft_strnstr(big, little, len));
	printf("****\nstrnstr:\nbig = %s\nlittle = %s\nlen = %zu\nreturn = %p"
			"\n",big, little, len, strnstr(big, little, len));
	return (0);
}*/
