/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:01:16 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/05 12:22:58 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//ft_strlcpy can be substituted with a static function here
//ft_strlcat can be substituted with a static function here
//Total number of functions (including above): 4

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	alloc_size;
	char	*join_s;

	if (!s1 || !s2)
		return (NULL);
	alloc_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join_s = malloc(alloc_size);
	if (!join_s)
		return (NULL);
	ft_strlcpy(join_s, s1, alloc_size);
	ft_strlcat(join_s, s2, alloc_size);
	return (join_s);
}
/*
int	main(void)
{
	const char	*s1 = "BLOOD FOR THE BLOOD GOD!";
	const char	*s2 = "SKULLS FOR THE SKULL THRONE!";
	char		*s3;

	s3 = ft_strjoin(s1, s2);
	printf("s1=%s\ns2=%s\ns3=%s\n", s1, s2, s3);
	free(s3);
	printf("s3 freed successfully");
	return (0);
}*/
