#include "push_swap.h"

void	sb(t_stack **b)
{
	swap(b);
}

void	pb(t_stack **a, t_stack**b)
{
	push_to_stack(b, a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}
