/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:50:00 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:01:43 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	capitalise(unsigned int i, char c)
{
	(void)i;

	c = ft_toupper(c);
	return (c);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
	{
		printf("INVALID/EMPTY INPUT. EXITING\n");
		exit(EXIT_FAILURE);
	}
	str = ft_strmapi(argv[1], capitalise);
	printf("original str=%s\nfuntction to apply=capitalise\n"
			"result str=%s\n", argv[1], str);
	free(str);
	printf("str freed successfully");
	return (0);
}*/
