#include "push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
}

void	pa(t_stack **a, t_stack**b)
{
	push_to_stack(a, b);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}