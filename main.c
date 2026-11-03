/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:55 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:55 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init(argc, argv);
	b = NULL;
	printf("first: %d, ", a->value);
	printf("next: %d, ", a->next->value);
	printf("last: %d\n", stack_last(a)->value);
	pb(&a, &b);
	printf("A\nnew first: %d, ", a->value);
	printf("next: %d, ", a->next->value);
	printf("last: %d\n", stack_last(a)->value);
	printf("B\nnew first: %d, ", b->value);
	printf("last: %d\n", stack_last(b)->value);
}
