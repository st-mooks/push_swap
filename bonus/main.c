/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:52:53 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/11 21:23:36 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	char	*op;

	argc = split_args(&argv);
	a = stack_init(argc, argv, get_option(argc, argv), get_bench_output(argv));
	b = NULL;
	ops = init_ops();
	op = get_next_line(0);
	check_op(op);
	while (op)
	{
		apply_op(op, &a, &b, &ops);
		free(op);
		op = get_next_line(0);
		check_op(op);
	}
	if (!compute_disorder(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
