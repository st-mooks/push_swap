/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:11:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/06 14:21:33 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int	main(int argc, char *argv[])
{
	int	c;

	if (argc != 2)
	{
		printf("INVALID/EMPTY INPUT. EXITING\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) > 1)
		c = ft_atoi(argv[1]);
	else
		c = argv[1][0];
	printf("ft_toupper(%c) = %c\n", c, ft_toupper(c));
	printf("toupper(%c) = %c\n", c, toupper(c));
	return (0);
}*/
