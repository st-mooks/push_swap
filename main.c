#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = stcknew(42);
	b = stcknew(0);
	push(&a, 43);
	push(&a, 44);
	push(&a, 45);
	push(&b, 1);
	push(&b, 2);
	push(&b, 3);
	printf("a:\nvalue1:%d, value2:%d, value3:%d, value4:%d\n", a->value, a->next->value, a->next->next->value, stcklast(a)->value);
	printf("b:\nvalue1:%d, value2:%d, value3:%d, value4:%d\n", b->value, b->next->value, b->next->next->value, stcklast(b)->value);
	sa(&a);
	printf("******\nsa:\nvalue1:%d, value2:%d, value3:%d, value4:%d\n******\n", a->value, a->next->value, a->next->next->value, stcklast(a)->value);
	sb(&b);
	printf("******\nsb:\nvalue1:%d, value2:%d, value3:%d, value4:%d\n******\n", b->value, b->next->value, b->next->next->value, stcklast(b)->value);
	pa(&a, &b);
	printf("******\npa:\na:\nvalue1:%d, value2:%d, value3:%d, value4:%d, value5:%d\n", a->value, a->next->value, a->next->next->value, a->next->next->next->value, stcklast(a)->value);
	printf("b:\nvalue1:%d, value2:%d, value3:%d\n******\n", b->value, b->next->value, stcklast(b)->value);
	pb(&a, &b);
	pb(&a, &b);
	printf("******\npb (x2):\na:\nvalue1:%d, value2:%d, value3:%d\n", a->value, a->next->value, stcklast(a)->value);
	printf("b:\nvalue1:%d, value2:%d, value3:%d, value4:%d, value5:%d\n******\n", b->value, b->next->value,b->next->next->value, b->next->next->next->value, stcklast(b)->value);
	ra(&a);
	printf("******\nra:\na:\nvalue1:%d, value2:%d, value3:%d\n******\n", a->value, a->next->value, stcklast(a)->value);
	rb(&b);
	printf("******\nb:\nvalue1:%d, value2:%d, value3:%d, value4:%d, value5:%d\n******\n******\n", b->value, b->next->value,b->next->next->value, b->next->next->next->value, stcklast(b)->value);
}