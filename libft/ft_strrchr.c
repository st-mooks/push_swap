/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:16:57 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 14:44:54 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_cpy;

	c = (unsigned char)c;
	s_cpy = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (s_cpy + i);
	while (i > 0)
	{
		if (s[i - 1] == c)
		{
			return (&s_cpy[i - 1]);
		}
		i--;
	}
	return (NULL);
}
/*
int	main(int argc, char *argv[])
{
	char	*s;
	int		c;

	if (argc != 3)
	{
		printf("INVALID/EMPTY INPUT.\nVALID INPUT NO.: 2. I.E.: CHAR *, INT"
				"\nEXITING\n");
		exit(EXIT_FAILURE);
	}
	s = argv[1];
	if (ft_strlen(argv[2]) > 1)
		c = ft_atoi(argv[2]);
	else
		c = argv[2][0];
	printf("ft_strrchr:\ns=\"%s\" c=\'%c\'\nreturn = %p\n"
			"", s, c, ft_strrchr(s, c));
	printf("****\nstrrchr:\ns=\"%s\" c=\'%c\'\nreturn = %p\n"
			"", s, c, strrchr(s, c));
	return (0);
}*/
