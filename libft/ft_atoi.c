/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:12:00 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/03 12:51:56 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_isdigit can be substituted with a static function here
//Total number of functions (including above): 3

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	sum;
	int			sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			break ;
		sum *= 10;
		sum += (int)(*nptr - '0');
		nptr++;
	}
	return ((int)(sum * sign));
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("INVALID/EMPTY INPUT. EXITING\n");
		exit(EXIT_FAILURE);
	}
	printf("ft_atoi:\nnptr = %s\nreturn = %d\n", argv[1], ft_atoi(argv[1]));
	printf("****\natoi:\nnptr = %s\nreturn = %d\n", argv[1], atoi(argv[1]));
	return (0);
}*/