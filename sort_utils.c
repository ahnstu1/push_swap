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