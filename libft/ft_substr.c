/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:15:03 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:09:14 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//ft_strdup can be substituted with a static function here
//ft_strlcpy can be substituted with a static function here
//Total number of functions (including above): 4

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	original_len;
	size_t	size;

	if (!s)
		return (NULL);
	original_len = ft_strlen(s);
	if (start >= original_len)
		return (ft_strdup(""));
	if (original_len >= start + len)
		size = len + 1;
	else
		size = original_len - start + 1;
	sub_s = malloc(size * sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, s + start, size);
	return (sub_s);
}
/*
int	main(int argc, char *argv[])
{
	const char		*s;
	char			*sub_s;
	unsigned int	start;
	size_t			len;

	if (argc != 4)
	{
		printf("INVALID INPUT.\nVALID INPUT NO.:2. I.E.: CHAR *, UNSIGNED INT"
				", SIZE_T\nEXITING\n");
		exit(EXIT_FAILURE);
	}
	s = (const char *)argv[1];
	start = ft_atoi(argv[2]);
	len = (size_t)ft_atoi(argv[3]);
	sub_s = ft_substr(s, start, len);
	printf("s=\"%s\"\nstart=%u, len=%zu\nsub_s=\"%s\"\n", s, start, len, sub_s);
	free(sub_s);
	printf("sub_s freed successfully\n");
	return (0);
}*/
