/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:47:24 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/11 13:47:27 by mbadarin         ###   ########.fr       */
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

void	fill_args(char **split, char **split_arg, int original_len)
{
	if (!split_arg)
		return ;
	while (*split_arg)
	{
		split[original_len++] = *split_arg;
		split_arg += 1;
	}
	split[original_len] = NULL;
}

void	free_arr(char **arr)
{
	if (!arr)
		return ;
	while (*arr)
	{
		free(*arr);
		arr += 1;
	}

}

int	split_args(char **argv[])
{
	char	**split_arg;
	char	**split;
	char	**temp;
	int		count;
	int		i;

	split = NULL;
	count = 0;
	i = 0;
	while ((*argv)[i])
	{
		split_arg = ft_split((*argv)[i++], ' ');
		count += count_args(split_arg);
		temp = split;
		split = malloc((count + 1) * sizeof(char *));
		fill_args(split, temp, 0);
		fill_args(split, split_arg, count_args(temp));
		free(split_arg);
		free(temp);
	}
	fill_args(*argv, split, 0);
	free(split);
	return (count);
}
