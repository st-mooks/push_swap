#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!stack || !*stack)
		return ;
	last = stcklast(*stack);
	penultimate = stckpenultimate(*stack);
	last->next = *stack;
	*stack = last;
	penultimate->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *last;

    if (!stack || !*stack)
        return ;
	last = *stack;
	*stack = (*stack)->next;
	stcklast(*stack)->next = last;
	last->next = NULL;
}
