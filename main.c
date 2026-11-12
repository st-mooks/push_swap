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

int	main(int argc, char *argv[])
{
	int		mode;
	int		bench_output;
	t_stack	*a;
	double	disorder;
	t_ops	*ops;

	argc = split_args(&argv);
	mode = get_option(argc, argv);
	bench_output = get_bench_output(argv);
	a = stack_init(argc, argv, mode, bench_output);
	disorder = compute_disorder(a);
	if (disorder == 0)
		return (0);
	assign_index(a);
	ops = get_ops(&a, mode, disorder);
	print_bench(*ops, bench_output, mode, disorder);
	if (bench_output != 1)
		print_ops(ops->ops_list);
	free_all(a, ops);
	free_arr(argv);
	return (0);
}
