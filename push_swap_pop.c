#include "push_swap.h"

void	push(t_stack **stack, int n)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	*stack = stcknew(n);
	(*stack)->next = temp;
}

void	pop(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	push_to_stack(t_stack **dest, t_stack **src)
{
	if (!dest || !src || !*src)
		return ;
	if (!*dest)
		*dest = stcknew((*src)->value);
	else
		push(dest, (*src)->value);
	pop(src);
}

void	swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if (!stack)
		return ;
	if (*stack && (*stack)->next)
	{
		second = *stack;
		third = (*stack)->next->next;
		*stack = (*stack)->next;
		(*stack)->next = second;
		(*stack)->next->next = third;
	}
}
