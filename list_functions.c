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

#include "push_swap.h"

t_stack	*stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		raise_error();
	new->value = n;
	new->next = NULL;
	return (new);
}

t_stack	*stack_penultimate(t_stack *stack)
{
	if (!stack)
		raise_error();
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		raise_error();
	while (stack->next)
		stack = stack->next;
	return (stack);
}

size_t	get_input_stack_len(int argc, char *argv[])
{
	size_t	len;
	int		i;

	if (argc <= 1)
		raise_error();
	i = argc - 1;
	len = i;
	while (i > 0)
	{
		if (!ft_strncmp(argv[i], "--bench", ft_strlen("--bench") + 1))
			len--;
		i--;
	}
	if (get_option(argc, argv))
		len--;
	return (len);
}

t_stack	*stack_init(size_t len, int argc, char *argv[])
{
	int		value;
	t_stack	*stack;

	value = ft_atoi(argv[--argc]);
	validate_int(value, argv[argc--]);
	stack = stack_new(value);
	len--;
	while (len > 0)
	{
		value = ft_atoi(argv[argc]);
		validate_int(value, argv[argc--]);
		check_duplicate(value, stack);
		push(&stack, value);
		len--;
	}
	return (stack);
}
