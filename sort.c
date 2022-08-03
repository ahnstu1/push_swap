/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:47:32 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 06:59:48 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_big(t_psts *ts)
{
	while (ts -> size_b > 1)
	{
		if (!pur_finder(ts, ts -> top_a -> num - 1, 0, 1))
			sort_rb(ts);
		else
			sort_rrb(ts);
	}
}

void	sort(t_psts *ts)
{
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
