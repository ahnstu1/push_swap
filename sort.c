#include "push_swap.h"

void	hard_two(t_psts *ts)
{
	if (ts -> top_a -> num > ts -> top_a -> next -> num)
		sa(ts);
}

void    hard_three(t_psts *ts)
{
    int fst;
    int snd;
    int trd;

    fst = ts -> top_a -> num;
    snd = ts -> top_a -> next -> num;
    trd = ts -> top_a -> next -> next -> num;
    if (fst > snd && snd > trd && fst > trd)
    {
		sa(ts);
		rra(ts);
    }
    else if (fst > snd && snd < trd && fst > trd)
		ra(ts);
    else if (fst < snd && snd > trd && fst < trd)
    {
		sa(ts);
		ra(ts);
    }
    else if (fst > snd && snd < trd && fst < trd)
		sa(ts);
    else if (fst < snd && snd > trd && fst > trd)
		rra(ts);
}

void    sort_big(t_psts *ts)
{
    int count;
    while (ts -> size_b != 1)
    {
        count = 0;
        if (!pur_finder(ts))
        {
            while (ts -> top_b -> num != ts -> top_a -> num - 1)
            {
                rb(ts);
                count++;
            }
            pa(ts);
        }
        else
        {
            while (ts -> top_b -> num != ts -> top_a -> num - 1)
            {
                rrb(ts);
                count++;
            }
            pa(ts);
        }
    }
}

void    sort(t_ps *stack_a, t_psts *ts)
{
	int		size;

	if (ts -> size_a == 2)
		hard_two(ts);
	else if (ts -> size_a == 3)
		hard_three(ts);
	else
	{
		stack_b_init(ts);
        sort_big(ts);
        write(1, "pa\n", 3);
	}
}