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

void    hard_f(t_psts *ts)
{
	int	size;

	while (ts -> size_a > 3)
	{
		if (ts -> top_a -> num == 0 || ts -> top_a -> num == 1)
			pb(ts);
		else
			ra(ts);
	}
	hard_three(ts);
	pa(ts);
	pa(ts);
	hard_three(ts);
}

void	sort_rb(t_psts *ts)
{
	int	count;
	int	tar;

	tar = ts -> top_a -> num - 1;
	count = 1;
	while (ts -> top_b -> num != tar)
	{
		if (ts -> top_b -> num == tar - count && count != 2)
		{
			count++;
			pa(ts);
		}
		else
			rb(ts);

	}
	pa(ts);
	if (count == 2)
		hard_two(ts);
}

void	sort_rrb(t_psts *ts)
{
	int	count;
	int	tar;

	tar = ts -> top_a -> num - 1;
	count = 1;
	while (ts -> top_b -> num != tar)
	{
		if (ts -> top_b -> num == tar - count && count != 2)
		{
			count++;
			pa(ts);
		}
		else
			rrb(ts);

	}
	pa(ts);
	if (count == 2)
		hard_two(ts);
}

void    sort_big(t_psts *ts)
{
    while (ts -> size_b > 1)
    {
        if (!pur_finder(ts, ts -> top_a -> num - 1, 0, 1))
			sort_rb(ts);
        else
            sort_rrb(ts);
    }
}

void    sort(t_ps *stack_a, t_psts *ts)
{
	int		size;

	if (ts -> size_a == 2)
		hard_two(ts);
	else if (ts -> size_a == 3)
		hard_three(ts);
	else if (ts -> size_a <= 5)
		hard_f(ts);
	else if (ts -> size_a > 5)
	{
		stack_b_init(ts);
        sort_big(ts);
        pa(ts);
	}
}