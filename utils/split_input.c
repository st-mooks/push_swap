/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:47:24 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/11 20:57:05 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_args(char *args[])
{
	int	count;

	if (!args)
		return (0);
	count = 0;
	while (*args)
	{
		count++;
		args += 1;
	}
	return (count);
}

void	free_arr(char **arr)
{
	char	**cpy;

	if (!arr)
		return ;
	cpy = arr;
	while (*arr)
	{
		free(*arr);
		arr += 1;
	}
	free(cpy);
}

void	fill_str(char **str, char *argv[])
{
	size_t	i;
	ssize_t	j;

	if (!argv)
		return ;
	i = ft_strlen(*argv);
	j = 0;
	while (*argv)
	{
		ft_memmove(*str + j, *argv, i);
		argv += 1;
		j += i;
		*(*str + j) = ' ';
		j++;
		if (*argv)
			i = ft_strlen(*argv);
	}
	*(*str + j) = '\0';
}

size_t	get_args_len(char *argv[])
{
	size_t	len;

	len = 0;
	while (*argv)
	{
		len += ft_strlen(*argv);
		argv += 1;
	}
	return (len);
}

int	split_args(char **argv[])
{
	size_t	len;
	char	*str;
	char	**split;

	*argv += 1;
	len = get_args_len(*argv);
	str = malloc(len * 2 * sizeof(char));
	fill_str(&str, *argv);
	split = ft_split(str, ' ');
	free(str);
	*argv = split;
	return (count_args(*argv));
}
