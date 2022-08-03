/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:17:13 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 08:04:43 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	crd_comp(t_ps *lst, int num)
{
	int		ret;
	t_ps	*cur;

	cur = lst;
	ret = 0;
	while (cur -> next)
	{
		if (cur -> num == num)
			return (ret);
		cur = cur -> next;
		ret++;
	}
	return (ret);
}

t_ps	*stack_a_init(t_ps **stack, t_ps *lst, char **argv)
{
	t_ps	*cur;
	int		idx;
	int		num;

	idx = 0;
	num_vali(argv[idx]);
	*stack = t_ps_new_node(crd_comp(lst, ft_atoi(argv[idx])), NULL, NULL);
	cur = *stack;
	while (argv[++idx])
	{
		num_vali(argv[idx]);
		num = ft_atoi(argv[idx]);
		cur -> next = t_ps_new_node(crd_comp(lst, num), NULL, cur);
		cur = cur -> next;
	}
	return (*stack);
}

void	stack_b_init(t_psts *ts)
{
	while (ts -> size_a > 1)
	{
		if (ts -> top_a -> num < ts -> pivot && ts -> top_a -> num + 1 \
			!= ts -> size && ts -> top_a -> num >= ts -> mid && ts -> pivot++)
			pb(ts);
		else if (ts -> top_a -> num >= ts -> pivot1 && \
			ts -> top_a -> num < ts -> mid && ts -> pivot1--)
		{
			pb(ts);
			rb(ts);
		}
		else
			ra(ts);
		if (!ts -> pviot_con)
		{
			ts -> pivot += ts -> chunk;
			ts -> pviot_con = ts -> chunk;
		}
		if (!ts -> pviot1_con)
		{
			ts -> pivot1 -= ts -> chunk;
			ts -> pviot1_con = ts -> chunk;
		}
	}
}
