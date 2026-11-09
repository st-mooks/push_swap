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
	int		mode;
	int		bench_output;
	double	disorder;
	t_ops	*ops;

	a = stack_init(argc, argv);
	mode = get_option(argc, argv);
	bench_output = get_bench_output(argc, argv);
	disorder = compute_disorder(a);
	ops = get_ops(a, mode, bench_output, disorder);
	print_bench(ops, bench_output, mode, disorder);
	if (bench_output != 1)
		print_ops(ops->ops_list);
	free(a);
	free(ops);
}
