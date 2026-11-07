/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:53:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 20:27:29 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	capitalise(unsigned int i, char *s)
{
	(void) i;
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("INVALID/EMPTY INPUT.\nVALID INPUT NO. :1. I.E. CAHR *"
				"EXITING\n");
		exit(EXIT_FAILURE);
	}
	printf("Original str=\"%s\"\n", argv[1]);
	ft_striteri(argv[1], capitalise);
	printf("function=capitalise\nresult str="
			"\"%s\"", argv[1]);
	return (0);
}*/
