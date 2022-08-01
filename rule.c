/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:24:52 by hahn              #+#    #+#             */
/*   Updated: 2022/08/02 01:18:56 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps *cur)
{
	int	next;

	if (cur && cur -> next)
	{
		next = cur -> next -> num;
		cur -> next -> num = cur -> num;
		cur -> num = next;
	}
}

void	push(t_ps **in, t_ps **out, int size_in, int size_out)
{
	t_ps	*tmp;

	if (!size_out)
		return ;
	tmp = *out;
	if ((*out) -> next)
	{
		*out = (*out) -> next;
		(*out) -> prev = NULL;
	}
	if (!size_in)
	{
		tmp -> next = NULL;
		*in = tmp;
	}
	else
	{
		tmp -> next = *in;
		(*in) -> prev = tmp;
		*in = tmp;
	}
}

void	rotate(t_ps **cur)
{
	t_ps	*ret;
	t_ps	*tmp;

	if (*cur && (*cur) -> next)
	{
		ret = (*cur) -> next;
		tmp = *cur;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = *cur;
		(*cur) -> prev = tmp;
		(*cur) -> next = NULL;
		ret -> prev = NULL;
		*cur = ret;
	}
}

void	*reverse_rotate(t_ps **cur)
{
	t_ps	*ret;

	if (*cur && (*cur) -> next)
	{
		ret = *cur;
		while (ret -> next)
			ret = ret -> next;
		ret -> prev -> next = NULL;
		ret -> prev = NULL;
		ret -> next = (*cur);
		(*cur) -> prev = ret;
		*cur = ret;
	}
}