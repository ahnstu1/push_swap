#include "push_swap.h"

void	sa(t_pstp *top)
{
	swap(top -> a_top);
	//write(1, "sa\n", 3);
}

void	sb(t_pstp *top)
{
	swap(top -> b_top);
	//write(1, "sb\n", 3);
}

void	pa(t_pstp *top)
{
	push(top -> a_top, top -> b_top, top -> size_a, top -> size_b);
	top -> size_a++;
	top -> size_b--;
	//write(1, "pa\n", 3);
}

void	pb(t_pstp *top)
{
	push(top -> b_top, top -> a_top, top -> size_b, top -> size_a);
	top -> size_a--;
	top -> size_b++;
	//write(1, "pb\n", 3);
}

void	ss(t_pstp *top)
{
	swap(top -> a_top);
	swap(top -> b_top);
	//write(1, "ss\n", 3);
}