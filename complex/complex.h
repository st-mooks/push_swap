/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.h                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kalnajja <kalnajja@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 14:18:43 by kalnajja         #+#    #+#              */
/*   Updated: 2026/11/12 16:05:10 by kalnajja        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include "../push_swap.h"

typedef struct s_partition
{
	int	size;
	int	rotated;
}	t_partition;

void	assign_index(t_stack *stack);
int		stack_size(t_stack *stack);
int		get_pivot(int min, int max);
int		min_index(t_stack *stack, int size);
int		max_index(t_stack *stack, int size);
int		partition_a(t_stack **a, t_stack **b, int size, t_ops **ops);
int		partition_b(t_stack **a, t_stack **b, int size, t_ops **ops);
void	quick_sort_a(t_stack **a, t_stack **b, int size, t_ops **ops);
void	quick_sort_b(t_stack **a, t_stack **b, int size, t_ops **ops);
t_ops	*complex_sort(t_stack **a);

#endif
