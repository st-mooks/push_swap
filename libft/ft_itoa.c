/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:36:05 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/05 09:19:19 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(char *str, int n, int digits)
{
	char		*base;
	long long	l;

	l = (long long) n;
	if (l < 0)
	{
		l *= -1;
		*str = '-';
	}
	base = "0123456789";
	if (l == 0)
		*str = '0';
	while (l > 0)
	{
		str[digits - 1] = base[l % 10];
		l /= 10;
		digits--;
	}
}

static int	count_digits(int n)
{
	int			digits;
	long long	l;

	digits = 0;
	l = (long long)n;
	if (l < 0)
	{
		l *= -1;
		digits++;
	}
	if (l == 0)
		digits++;
	while (l > 0)
	{
		digits++;
		l /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*str;

	digits = count_digits(n);
	str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_str(str, n, digits);
	str[digits] = '\0';
	return (str);
}
/*
int	main(int argc, char *argv[])
{
	char	*str;
	int		n;

	if (argc != 2)
		{
			printf("INVALID/EMPTY INPUT. EXITING\n");
			exit(EXIT_FAILURE);
		}

	n = ft_atoi(argv[1]);
	str = ft_itoa(n);
	printf("n=%d\nstr=%s\nft_strlen(str)=%zu\n", n, str, ft_strlen(str));
	return (0);
}*/
