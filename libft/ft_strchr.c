/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:16:57 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 14:30:31 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if ((unsigned char)*s == c)
			return ((char *)s);
		s++;
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
		printf("INVALID/EMPTY INPUT. EXITING\n");
		exit(EXIT_FAILURE);
	}
	s = argv[1];
	if (ft_strlen(argv[2]) > 1)
		c = atoi(argv[2]);
	else
		c = argv[2][0];
	printf("ft_strchr:\ns=\"%s\" c=\'%c\'\nreturn = %p\n"
			"", s, c, ft_strchr(s, c));
	printf("****\nstrchr:\ns=\"%s\" c=\'%c\'\nreturn = %p\n"
			"", s, c, strchr(s, c));
	return (0);
}*/
