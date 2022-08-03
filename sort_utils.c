/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:47:28 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 07:00:38 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_ps *stack)
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

int	pur_finder(t_psts *ts, int pur, int count, int count1)
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

void	hard_two(t_psts *ts)
{
	if (ts -> top_a -> num > ts -> top_a -> next -> num)
		sa(ts);
}

void	hard_three(t_psts *ts)
{
	int	fst;
	int	snd;
	int	trd;

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

void	hard_f(t_psts *ts)
{
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
