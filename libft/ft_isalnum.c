/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:11:42 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/11 12:40:15 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Note that while man page specified that the value of c
//"must have the value of an unsigned char or EOF",
//the behaviour of the function matches more if the comparison is done on
//the raw uncast int value instead. The casting to unsigned char is kept for
//the purpose of matching the man page **EVEN THOUGH THE BEHAVIOUR DIFFERS**.

#include "libft.h"

//ft_isalpha can be substituted with a static function here
//ft_isdigit can be substituted with  a static function here
//Total number of functions (including above): 3

int	ft_isalnum(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return (ft_isdigit(ch) || ft_isalpha(ch));
}
/*
int	main(int argc, char *argv[])
{
	char	c;
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
	if (!ft_isalnum(c))
		printf("not ");
	printf("alphanumeric!\n");
	printf("isalnum says: %d\n", isalnum(c));
	return (0);
}*/
