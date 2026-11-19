/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:13:39 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:08:05 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//ft_strlcpy can be substituted with a static function here
//ft_strdup can be substituted with a static function here
//Total number of functions (including above): 5

static int	char_in_set(const char *set, char c)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim_s;
	const char	*start;
	const char	*end;
	size_t		len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = s1;
	while (char_in_set(set, *start))
		start++;
	if (!*start)
		return (ft_strdup(""));
	end = s1 + len - 1;
	while (char_in_set(set, *end) && ft_strlen(end) < len)
		end--;
	trim_s = malloc((end - start + 2) * sizeof(char));
	if (!trim_s)
		return (NULL);
	ft_strlcpy(trim_s, start, end - start + 2);
	return (trim_s);
}
/*
int	main(int argc, char *argv[])
{
	const char	*s1;
	const char	*set;
	char		*s2;

	if (argc != 3)
	{
		printf("INVALID INPUT.\nVALID INPUT NO.: 2. I.E.: CHAR *, CHAR *\n"
				"EXITING\n");
		exit(EXIT_FAILURE);
	}
	s1 = argv[1];
	set = argv[2];
	s2 = ft_strtrim(s1, set);
	printf("s1=\"%s\" set=\"%s\"\ns2=\"%s\"\n", s1, set, s2);
	free(s2);
	printf("s2 freed successfully\n");
	return (0);
}*/
