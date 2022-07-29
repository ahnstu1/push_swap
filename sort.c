#include "push_swap.h"

void	hard_two(t_ps *stack)
{
	if (stack -> num > stack -> next -> num)
		swap(stack);
}

void    hard_three(t_ps *stack)
{
    int fst;
    int snd;
    int trd;

    fst = stack -> num;
    snd = stack -> next -> num;
    trd = stack -> next -> next -> num;
    if (fst > snd && snd > trd && fst > trd)
    {
        stack = swap(stack);
        stack = reverse_rotate(stack);
    }
    else if (fst > snd && snd < trd && fst > trd)
        stack = rotate(stack);
    else if (fst < snd && snd > trd && fst < trd)
    {
        stack = swap(stack);
        stack = rotate(stack);
    }
    else if (fst > snd && snd < trd && fst < trd)
        stack = swap(stack);
    else if (fst < snd && snd > trd && fst > trd)
        stack = reverse_rotate(stack);
}

void    sort(t_ps *stack_a)
{
	int		size;
	t_ps	*stack_b;

	size = get_size(stack_a);
	if (size == 2)
		hard_two(stack_a);
	else if (size == 3)
		hard_three(stack_a);
	else
	{
		stack_b_init(stack_a, stack_b, size);
		lst_test(stack_b);
	}
}