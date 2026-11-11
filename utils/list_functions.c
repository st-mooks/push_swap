/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 list_functions.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:43 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:43 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = n;
	new->next = NULL;
	return (new);
}

t_stack	*stack_penultimate(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_all(t_stack *a, t_ops *ops)
{
	t_stack		*stack_next;
	t_ops_list	*ops_next;

	if (a)
	{
		while (a)
		{
			stack_next = a->next;
			free(a);
			a = stack_next;
		}
	}
	if (ops)
	{
		while (ops->ops_list)
		{
			ops_next = ops->ops_list->next;
			free(ops->ops_list);
			ops->ops_list = ops_next;
		}
		free(ops);
	}
}

t_stack	*stack_init(int argc, char *argv[])
{
	int		value;
	t_stack	*stack;
	int		i;
	size_t	len;

	i = argc - 1;
	len = get_input_stack_len(argc, argv);
	stack = NULL;
	while ((size_t)i >= argc - len)
	{
		value = ft_atoi(argv[i]);
		if (!validate_int(argv[i--])
			|| !check_duplicate(value, stack))
		{
			free_all(stack, NULL);
			raise_error();
		}
		push(&stack, value);
	}
	return (stack);
}
