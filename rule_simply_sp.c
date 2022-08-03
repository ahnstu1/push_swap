/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_simply_sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:47:07 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 06:47:07 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_psts *ts)
{
	swap(ts -> top_a);
	write(1, "sa\n", 3);
}

void	sb(t_psts *ts)
{
	swap(ts -> top_b);
	write(1, "sb\n", 3);
}

void	pa(t_psts *ts)
{
	if (ts -> size_b)
	{
		push(&ts -> top_a, &ts -> top_b, ts -> size_a, ts -> size_b);
		ts -> size_a++;
		ts -> size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_psts *ts)
{
	if (ts -> size_a)
	{
		push(&ts -> top_b, &ts -> top_a, ts -> size_b, ts -> size_a);
		ts -> size_a--;
		ts -> size_b++;
		write(1, "pb\n", 3);
	}
}

void	ss(t_psts *ts)
{
	swap(ts -> top_a);
	swap(ts -> top_b);
	write(1, "ss\n", 3);
}
