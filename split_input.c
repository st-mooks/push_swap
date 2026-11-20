/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:47:24 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/16 14:43:52 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

	if (!argv || !*argv)
	{
		**str = '\0';
		return ;
	}
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
	size_t	len_single_arg;

	len = 0;
	while (*argv)
	{
		len_single_arg = ft_strlen(*argv);
		if (len_single_arg == 0)
			raise_error();
		len += len_single_arg;
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
	if (len == 0)
		len = 1;
	str = malloc(len * 2 * sizeof(char) + 1);
	if (!str)
		raise_error();
	fill_str(&str, *argv);
	split = ft_split(str, ' ');
	free(str);
	*argv = split;
	return (count_args(*argv));
}
