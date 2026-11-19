/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:28:49 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 15:08:27 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Note that while man page specified that the value of c
//"must have the value of an unsigned char or EOF",
//the behaviour of the function matches more if the comparison is done on
//the raw uncast int value instead. The casting to unsigned char is kept for
//the purpose of matching the man page **EVEN THOUGH THE BEHAVIOUR DIFFERS**.

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
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
	printf("%c is ", c);
	if (!ft_isalpha(c))
		printf("not ");
	printf("alpha!\n");
	printf("isalpha says: %d", isalpha(c));
	return (0);
}*/
