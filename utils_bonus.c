/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 apply_ops.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/11 13:52:59 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/11 13:52:59 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static int	is_op(char *op, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	return (!ft_strncmp(op, name, len) && (op[len] == '\n' || !op[len]));
}

void	apply_op(char *op, t_stack **a, t_stack **b, t_ops **ops)
{
	if (is_op(op, "sa"))
		sa(a, ops);
	else if (is_op(op, "sb"))
		sb(b, ops);
	else if (is_op(op, "ss"))
		ss(a, b, ops);
	else if (is_op(op, "pa"))
		pa(a, b, ops);
	else if (is_op(op, "pb"))
		pb(a, b, ops);
	else if (is_op(op, "ra"))
		ra(a, ops);
	else if (is_op(op, "rb"))
		rb(b, ops);
	else if (is_op(op, "rr"))
		rr(a, b, ops);
	else if (is_op(op, "rra"))
		rra(a, ops);
	else if (is_op(op, "rrb"))
		rrb(b, ops);
	else if (is_op(op, "rrr"))
		rrr(a, b, ops);
}

int	check_op(char *op)
{
	if (!op
		|| is_op(op, "sa") || is_op(op, "sb") || is_op(op, "ss")
		|| is_op(op, "pa") || is_op(op, "pb")
		|| is_op(op, "ra") || is_op(op, "rb") || is_op(op, "rr")
		|| is_op(op, "rra") || is_op(op, "rrb") || is_op(op, "rrr"))
		return (1);
	free(op);
	return (0);
}

void	raise_error_bonus(char *argv[], t_stack **a, t_stack **b, t_ops **ops)
{
	free_all(*a, *ops);
	if (b)
		free_all(*b, NULL);
	free_arr(argv);
	raise_error();
}

void	parse_ops(char *argv[], t_stack **a, t_stack **b, t_ops **ops)
{
	char	*op;

	op = get_next_line(0);
	if (!check_op(op))
		raise_error_bonus(argv, a, b, ops);
	while (op)
	{
		apply_op(op, a, b, ops);
		free(op);
		op = get_next_line(0);
		if (!check_op(op))
			raise_error_bonus(argv, a, b, ops);
	}
}
