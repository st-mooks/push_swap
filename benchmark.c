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

#include "push_swap.h"

int	get_bench_output(int argc, char *argv[])
{
	while (--argc > 0)
	{
		if (!ft_strncmp(argv[argc], "--bench", ft_strlen("--bench") + 1))
			return (1);
	}
	return (2);
}
