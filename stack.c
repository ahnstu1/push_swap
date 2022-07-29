/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:17:13 by hahn              #+#    #+#             */
/*   Updated: 2022/07/30 03:11:26 by hahn             ###   ########.fr       */
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
	*stack = t_ps_new_node(crd_comp(lst, ft_atoi(argv[idx])), NULL, NULL);
	cur = *stack;
	while (argv[++idx])
	{
		num = ft_atoi(argv[idx]);
		cur -> next = t_ps_new_node(crd_comp(lst, num), NULL, cur);
		cur = cur -> next;
	}
	return (*stack);
}

void	*stack_b_init(t_pstp *top, int size)
{
	int		count;

	count = size;
	while (count < size / 3)
	{
		if (top -> a_top -> num < size / 3)
		{
			pb(top);
		}
		else if (top -> a_top -> num < size * 2 / 3)
		{
			pb(top);
			rotate(top -> b_top);
			count--;
		}
		else
			rotate(top -> a_top);
	}
}
