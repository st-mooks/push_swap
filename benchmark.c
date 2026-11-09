/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:42:42 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/09 11:42:45 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_bench_output(int argc, char *argv[])
{
    while (--argc > 0)
    {
        if (!ft_strncmp(argv[argc], "--bench", ft_strlen("--bench") + 1))
            return (1);
    }
    return (2);
}

void    print_bench(t_ops *ops, int bench_output, char *strategy)
{
    ft_putstr_fd("[bench] disorder:\t", bench_output);
    ft_putstr_fd("0.00%\n[bench] strategy:\t", bench_output);
    ft_putstr_fd(strategy, bench_output);
    ft_putstr_fd("\n[bench] total_ops:\t", bench_output);
    ft_putnbr_fd(ops->total, bench_output);
}