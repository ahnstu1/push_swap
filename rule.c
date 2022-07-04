/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:24:52 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 19:46:12 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

 t_ps	*swap(t_ps *cur)
 {
    t_ps   *next;

    if (!cur || !cur -> next)
        return ;
    next = cur -> next;
    cur -> next = next -> next;
    next -> prev = NULL;
    next -> next = cur;
    cur -> prev = next;
	return (next);
 }

 t_ps	*push(t_ps *in, t_ps *out)
 {
	t_ps	*ret;

	if (!out)
		return (NULL);
	ret = out -> next;
	if (!in)
	{
		in = out;
		out -> next = NULL;
	}
	else
	{
		in -> prev = out;
		ret -> prev = NULL;
		out -> next = in;
	}
	return (ret);
 }

 t_ps	*rotate(t_ps *cur)
 {
	t_ps	*ret;
	t_ps	*tmp;

	if (!cur || !cur -> next)
		return (cur);
	ret = cur -> next;
	tmp = cur;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = cur;
	cur -> prev = tmp;
	cur -> next = NULL;
	ret -> prev = NULL;
	return (ret);
 }

 t_ps	*reverse_rotate(t_ps *cur)
 {
    t_ps	*ret;

	if (!cur || !cur -> next)
		return (cur);
	ret = cur;
	while (ret -> next)
		ret = ret -> next;
	ret -> prev -> next = NULL;
	ret -> prev = NULL;
	ret -> next = cur;
	cur -> prev = ret;
	return (ret);
 }
