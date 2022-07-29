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
        swap(stack);
        reverse_rotate(stack);
    }
    else if (fst > snd && snd < trd && fst > trd)
        rotate(stack);
    else if (fst < snd && snd > trd && fst < trd)
    {
       swap(stack);
        rotate(stack);
    }
    else if (fst > snd && snd < trd && fst < trd)
        swap(stack);
    else if (fst < snd && snd > trd && fst > trd)
        reverse_rotate(stack);
}

void    sort(t_ps *stack_a)
{
	int		size;
	t_ps	*stack_b;
    t_pstp	*top;

	size = get_size(stack_a);
	if (size == 2)
		hard_two(stack_a);
	else if (size == 3)
		hard_three(stack_a);
	else
	{
        top -> a_top = stack_a;
        top -> b_top -> num = -1;
		stack_b_init(top, size);
        printf("\n----stack_b_init_after----");
        lst_test(stack_a);
        printf("\n----stack_b----\n");
		lst_test(stack_b);
	}
}