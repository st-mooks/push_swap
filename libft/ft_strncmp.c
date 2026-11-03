/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:48:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 20:53:30 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	i = 0;
	while ((s1_cpy[i] || s2_cpy[i]) && i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	char const	*s1;
	char const	*s2;
	size_t		n;

	if (argc != 4)
	{
		printf("INVALID/EMPTY INPUT.\nVALID INPUT NUM 3."
				"I.E. CHAR * CHAR * SIZE_T\nEXITING\n");
		exit(EXIT_FAILURE);
	}
	s1 = argv[1];
	s2 = argv[2]; 
	n = (size_t)ft_atoi(argv[3]);
	printf("ft_strncmp:\ns1 = %s\ns2 = %s\nn = %zu\nreturn = "
			"%d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n****\nstrncmp:\ns1 = %s\ns2 = %s\nn = %zu\nreturn = "
			"%d", s1, s2, n, strncmp(s1, s2, n));
	return (0);
}*/
