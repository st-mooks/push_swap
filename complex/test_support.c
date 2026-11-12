/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_support.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kalnajja <kalnajja@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 13:44:57 by kalnajja         #+#    #+#              */
/*   Updated: 2026/11/12 13:49:30 by kalnajja        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

/* Stack functions */

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, int value)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = new_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	push_to_stack(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (!dest || !src || !*src)
		return ;
	node = *src;
	*src = node->next;
	node->next = *dest;
	*dest = node;
}

void	swap(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* Operations logging */

t_ops_list	*init_ops_list(char *op_name)
{
	t_ops_list	*node;

	node = malloc(sizeof(t_ops_list));
	if (!node)
		return (NULL);
	node->op = op_name;
	node->next = NULL;
	return (node);
}

t_ops	*init_ops(void)
{
	t_ops	*ops;

	ops = malloc(sizeof(t_ops));
	if (!ops)
		return (NULL);
	ops->ops_list = init_ops_list(NULL);
	if (!ops->ops_list)
	{
		free(ops);
		return (NULL);
	}
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
	ops->total = 0;
	return (ops);
}

void	add_op_to_list(t_ops **ops, char *op_name)
{
	t_ops_list	*node;
	t_ops_list	*last;

	if (!ops || !*ops || !(*ops)->ops_list)
		return ;
	if (!(*ops)->ops_list->op)
	{
		(*ops)->ops_list->op = op_name;
		return ;
	}
	node = init_ops_list(op_name);
	if (!node)
		return ;
	last = (*ops)->ops_list;
	while (last->next)
		last = last->next;
	last->next = node;
}

/* Operation wrappers */

void	sa(t_stack **a, t_ops **ops)
{
	swap(a);
	add_op_to_list(ops, "sa");
	(*ops)->sa_count++;
	(*ops)->total++;
}

void	sb(t_stack **b, t_ops **ops)
{
	swap(b);
	add_op_to_list(ops, "sb");
	(*ops)->sb_count++;
	(*ops)->total++;
}

void	pa(t_stack **a, t_stack **b, t_ops **ops)
{
	push_to_stack(a, b);
	add_op_to_list(ops, "pa");
	(*ops)->pa_count++;
	(*ops)->total++;
}

void	pb(t_stack **a, t_stack **b, t_ops **ops)
{
	push_to_stack(b, a);
	add_op_to_list(ops, "pb");
	(*ops)->pb_count++;
	(*ops)->total++;
}

void	ra(t_stack **a, t_ops **ops)
{
	rotate(a);
	add_op_to_list(ops, "ra");
	(*ops)->ra_count++;
	(*ops)->total++;
}

void	rb(t_stack **b, t_ops **ops)
{
	rotate(b);
	add_op_to_list(ops, "rb");
	(*ops)->rb_count++;
	(*ops)->total++;
}

void	rra(t_stack **a, t_ops **ops)
{
	reverse_rotate(a);
	add_op_to_list(ops, "rra");
	(*ops)->rra_count++;
	(*ops)->total++;
}

void	rrb(t_stack **b, t_ops **ops)
{
	reverse_rotate(b);
	add_op_to_list(ops, "rrb");
	(*ops)->rrb_count++;
	(*ops)->total++;
}

void	free_all(t_stack *a, t_ops *ops)
{
	t_ops_list	*current;
	t_ops_list	*next;

	(void) a;
	if (!ops)
		return ;
	current = ops->ops_list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(ops);
}
