#include "push_swap.h"

void	ra(t_psts *ts)
{
	rotate(&ts -> top_a);
	write(1, "ra\n", 3);
	ts -> count++;
}

void	rb(t_psts *ts)
{
	rotate(&ts -> top_b);
	write(1, "rb\n", 3);
	ts -> count++;
}

void	rra(t_psts *ts)
{
	reverse_rotate(&ts -> top_a);
	write(1, "rra\n", 4);
	ts -> count++;
}

void	rrb(t_psts *ts)
{
	reverse_rotate(&ts -> top_b);
	write(1, "rrb\n", 4);
	ts -> count++;
}