/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ops_utils.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 20:06:43 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 20:06:43 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

t_ops_list	*init_ops_list(void)
{
	t_ops_list	*ops_list;

	ops_list = malloc(sizeof(t_ops_list));
	if (!ops_list)
		raise_error();
	ops_list->op = NULL;
	ops_list->next = NULL;
	return (ops_list);
}

t_ops	*init_ops(void)
{
	t_ops	*ops;

	ops = malloc(sizeof(t_ops));
	if (!ops)
		raise_error();
	ops->ops_list = init_ops_list();
	ops->sa_count = 0;
	ops->sb_count = 0;
	ops->ss_count = 0;
	ops->pa_count = 0;
	ops->pb_count = 0;
	ops->ra_count = 0;
	ops->rb_count = 0;
	ops->rr_count = 0;
	ops->rra_count = 0;
	ops->rrb_count = 0;
	ops->rrr_count = 0;
	return (ops);
}

void	add_op_to_list(t_ops **ops, char *op_name)
{
	t_ops_list	*new_op;
	t_ops_list	*last;

	if (!ops)
		raise_error();
	new_op = malloc(sizeof(t_ops_list));
	if (!new_op)
		raise_error();
	if (!(*ops)->ops_list->op)
	{
		(*ops)->ops_list->op = ft_strdup(op_name);
		return ;
	}
	new_op->op = ft_strdup(op_name);
	last = ((*ops)->ops_list);
	while (last->next)
		last = last->next;
	last->next = new_op;
}

t_ops	*get_ops(t_stack *a, int mode, int bench_output, double disorder)
{
	t_ops	*ops;

	if (mode == 1 || (!mode && disorder < 0.2))
		ops = simple(&a);
	else if (mode == 2 || (!mode && 0.2 <= disorder && disorder < 0.5))
		ops = simple(&a);
	else
		ops = simple(&a);
	return (ops);
}
