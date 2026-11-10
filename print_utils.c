/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 print_utils.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/09 14:49:20 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/09 14:49:22 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_ops_list *ops_list)
{
	while (ops_list && ops_list->op)
	{
		write(1, ops_list->op, ft_strlen(ops_list->op));
		write(1, "\n", 1);
		ops_list = ops_list->next;
	}
}

void	print_ops_bench(t_ops ops, int bench_output)
{
	ft_putstr_fd("\n[bench] sa: ", bench_output);
	ft_putnbr_fd(ops.sa_count, bench_output);
	ft_putstr_fd("\tsb: ", bench_output);
	ft_putnbr_fd(ops.sb_count, bench_output);
	ft_putstr_fd("\tss: ", bench_output);
	ft_putnbr_fd(ops.ss_count, bench_output);
	ft_putstr_fd("\tpa: ", bench_output);
	ft_putnbr_fd(ops.pa_count, bench_output);
	ft_putstr_fd("\tpb: ", bench_output);
	ft_putnbr_fd(ops.pb_count, bench_output);
	ft_putstr_fd("\n[bench] ra: ", bench_output);
	ft_putnbr_fd(ops.ra_count, bench_output);
	ft_putstr_fd("\trb: ", bench_output);
	ft_putnbr_fd(ops.rb_count, bench_output);
	ft_putstr_fd("\trr: ", bench_output);
	ft_putnbr_fd(ops.rr_count, bench_output);
	ft_putstr_fd("\trra: ", bench_output);
	ft_putnbr_fd(ops.rra_count, bench_output);
	ft_putstr_fd("\trrb: ", bench_output);
	ft_putnbr_fd(ops.rrb_count, bench_output);
	ft_putstr_fd("\trrr: ", bench_output);
	ft_putnbr_fd(ops.rrr_count, bench_output);
}

void	print_bench(t_ops ops, int bench_output,
			int mode, double disorder)
{
	char	*strategy;

	strategy = get_strategy(mode, disorder);
	ft_putstr_fd("[bench] disorder:\t", bench_output);
	ft_putnbr_fd((int)(disorder * 100), bench_output);
	ft_putchar_fd('.', bench_output);
	ft_putnbr_fd((int)(disorder * 10000) % 100, bench_output);
	ft_putstr_fd("%\n[bench] strategy:\t", bench_output);
	ft_putstr_fd(strategy, bench_output);
	ft_putstr_fd("\n[bench] total_ops:\t", bench_output);
	ft_putnbr_fd(ops.total, bench_output);
	print_ops_bench(ops, bench_output);
	free(strategy);
}

char	*get_option_str(int mode)
{
	if (mode == 0)
		return ("Adaptive / ");
	if (mode == 1)
		return ("Simple / ");
	if (mode == 2)
		return ("Medium / ");
	else
		return ("Complex / ");
}

char	*get_strategy(int mode, double disorder)
{
	char	*strategy;

	strategy = get_option_str(mode);
	if (mode == 1 || (!mode && disorder < 0.2))
		strategy = ft_strjoin(strategy, "O(n2)");
	else if (mode == 2 || (!mode && 0.2 <= disorder && disorder < 0.5))
		strategy = ft_strjoin(strategy, "O(n√n)");
	else
		strategy = ft_strjoin(strategy, "O(nlog(n))");
	return (strategy);
}
