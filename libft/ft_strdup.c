/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:10:37 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 14:32:28 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen can be substituted with a static function here
//Total number of functions (including above): 2

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str_cpy;

	size = ft_strlen(s) + 1;
	str_cpy = malloc(size * sizeof(char));
	if (!str_cpy)
		return (NULL);
	while (*s)
		*str_cpy++ = *s++;
	*str_cpy++ = '\0';
	return (str_cpy - size);
}
/*
int	main(void)
{
	char	*str = "Copy this string";
	char	*ft_str_cpy;
	char	*str_cpy;

	ft_str_cpy = ft_strdup(str);
	printf("ft_strdup:\nstr = %s\nmemory location = %p\nstr_cpy = %s\n"
			"memory location = %p\n", str, str, ft_str_cpy, ft_str_cpy);
	str_cpy = strdup(str);
	printf("ft_strdup:\nstr = %s\nmemory location = %p\nstr_cpy = %s\n"
			"memory location = %p\n", str, str, str_cpy, str_cpy);
	free(ft_str_cpy);
	free(str_cpy);
	return (0);
}*/
