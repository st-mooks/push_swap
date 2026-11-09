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

void	init_options(char *options[])
{
	options[0] = "Adaptive";
	options[1] = "Simple";
	options[2] = "Medium";
	options[3] = "Complex";
}

char	*add_to_str(char *old, char *new)
{
	char	*temp;

	temp = old;
	old = ft_strjoin(old, new);
	free(temp);
	return (old);
}

void	select_print(t_stack *a, int mode, int bench_output, double disorder)
{
	char	*options[4];
	char	*strategy;
	t_ops	*ops;

	init_options(options);
	strategy = ft_strjoin(options[mode], " / ");
	if (mode == 1 || (!mode && disorder < 0.2))
	{
		ops = simple(&a);
		strategy = add_to_str(strategy, "O(n2)");
	}
	/* else if (mode == 2|| (!mode && 0.2 <= disorder && disorder < 0.5))
	{
		ops = medium(&a, len);
		strategy = add_to_str(strategy, "O(n√n)");
	}
	else
	{
		ops = complex(&a, len);
		strategy = add_to_str(strategy, "O(nlog(n))");
	}*/
	print_bench(ops, bench_output, strategy);
	print_ops(ops->ops_list);
	free(ops);
	free(strategy);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		mode;
	int		bench_output;
	double	disorder;

	disorder = 0.10;
	mode = get_option(argc, argv);
	bench_output = get_bench_output(argc, argv);
	printf("\n*****%d*****\n", bench_output);
	a = stack_init(argc, argv);
	select_print(a, mode, bench_output, disorder);
	free(a);
}
