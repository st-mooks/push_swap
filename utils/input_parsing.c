/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 benchmark.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/09 11:42:42 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/09 11:42:45 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_bench_output(char *argv[])
{
	while (*argv)
	{
		if (!ft_strncmp(*(argv++), "--bench", ft_strlen("--bench") + 1))
			return (1);
	}
	return (2);
}

int	get_input_stack_len(int argc, int mode, int bench_output)
{
	if (bench_output == 1)
		argc--;
	if (mode)
		argc--;
	return (argc);
}

void	check_duplicate_options(int argc, char *argv[])
{
	int		count;
	char	*str;

	count = 0;
	while (--argc > 0)
	{
		str = argv[argc];
		if (!ft_strncmp(str, "--simple", ft_strlen("--simple") + 1)
			|| !ft_strncmp(str, "--medium", ft_strlen("--medium") + 1)
			|| !ft_strncmp(str, "--complex", ft_strlen("--complex") + 1)
			|| !ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1))
			count++;
	}
	if (count > 1)
		raise_error();
}

int	get_option(int argc, char *argv[])
{
	int		option;
	char	*str;

	check_duplicate_options(argc, argv);
	option = 0;
	while (--argc >= 0)
	{
		str = argv[argc];
		if (!ft_strncmp(str, "--simple", ft_strlen("--simple") + 1))
			option = 1;
		if (!ft_strncmp(str, "--medium", ft_strlen("--medium") + 1))
			option = 2;
		if (!ft_strncmp(str, "--complex", ft_strlen("--complex") + 1))
			option = 3;
	}
	return (option);
}
