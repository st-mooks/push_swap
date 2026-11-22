/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:52:53 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/16 14:48:57 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	char	*op;

	argc = split_args(&argv);
	
	ops = init_ops();
	op = get_next_line(0);
	a = stack_init(argc, argv, get_option(argc, argv), get_bench_output(argv));
	if (!a)
		raise_error_bonus(argv, a, ops);
	b = NULL;
	if (!check_op(op))
		raise_error_bonus(argv, a, ops);
	while (op)
	{
		apply_op(op, &a, &b, &ops);
		free(op);
		op = get_next_line(0);
		if (!check_op(op))
			raise_error_bonus(argv, a, ops);
	}
	if (!compute_disorder(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(a, ops);
	free_arr(argv);
	return (0);
}
