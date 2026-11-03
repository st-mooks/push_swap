/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:56:29 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 14:40:26 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("INVALID INPUT. EXITING\n");
		exit(EXIT_FAILURE);
	}
	printf("string=\"%s\"\nft_strlen=%zu\n", argv[1], ft_strlen(argv[1]));
	printf("strlen=%zu\n", strlen(argv[1]));
}*/
