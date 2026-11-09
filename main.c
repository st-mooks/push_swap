/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:55 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:55 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	size_t	len;
	double	disorder;
	char	*option;
	int		bench_output;

	option = get_option(argc, argv);
	//bench_output = get_bench_output(argc, argv);
	len = get_input_stack_len(argc, argv);
	a = stack_init(len, argc, argv);
	disorder = 0.10;
	if (!ft_strncmp(option, "--simple", ft_strlen("--simple"))
			|| (!option && disorder < 0.2))
		simple(&a, len);
	/* else if (!ft_strncmp(option, "--medium", ft_strlen("--medium"))
			|| (!option && 0.2 <= disorder && disorder < 0.5))
		medium(&a, len);
	else
		complex(&a, len); */
	//print_bench(ops_list, ops_count, bench_output);
}
