#include "push_swap.h"

int		get_size(t_ps *stack)
{
	int		size;
	t_ps	*cur;

	size = 0;
	cur = stack;
	while (cur -> next)
	{
		size++;
		cur = cur -> next;
	}
	return (size + 1);
}

int		pur_finder(t_psts *ts, int pur, int count, int count1)
{
	t_ps	*stack_b;

	stack_b = ts -> top_b;
	while (stack_b -> num != pur && stack_b -> next && ++count)
		stack_b = stack_b -> next;
	while (stack_b -> next)
		stack_b = stack_b -> next;
	while (stack_b -> num != pur && stack_b -> prev && ++count1)
		stack_b = stack_b -> prev;
	return (count > count1);
}