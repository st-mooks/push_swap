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

t_ops_count	*init_ops_count(void)
{
	t_ops_count	*ops_count;

	ops_count = malloc(sizeof(t_ops_count));
	if (!ops_count)
		raise_error();
	ops_count->sa = 0;
	ops_count->sb = 0;
	ops_count->ss = 0;
	ops_count->pa = 0;
	ops_count->pb = 0;
	ops_count->ra = 0;
	ops_count->rb = 0;
	ops_count->rr = 0;
	ops_count->rra = 0;
	ops_count->rrb = 0;
	ops_count->rrr = 0;
	return (ops_count);
}

void	add_op_to_list(t_ops_list **ops_list, char *op_name)
{
	t_ops_list	*new_op;
	t_ops_list	*last;

	if (!ops_list)
		raise_error();
	new_op = malloc(sizeof(t_ops_list));
	if (!new_op)
		raise_error();
	if (!(*ops_list)->op)
	{
		(*ops_list)->op = ft_strdup(op_name);
		return ;
	}
	new_op->op = ft_strdup(op_name);
	last = (*ops_list);
	while (last->next)
		last = last->next;
	last->next = new_op;
}

void	print_ops(t_ops_list *ops_list)
{
	while (ops_list)
	{
		write(1, ops_list->op, ft_strlen(ops_list->op));
		write(1, "\n", 1);
		ops_list = ops_list->next;
	}
}
