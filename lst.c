/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:10:38 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 17:14:50 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps    *t_ps_new_node(int num, t_ps *next, t_ps *prev)
{
	t_ps	*output;

	output = (t_ps *)malloc(sizeof(t_ps) * 1);
	if (!output)
		return (0);
	output -> num = num;
	output -> next = next;
    output -> prev = prev;
	return (output);
}

int insert_next(t_ps **lst, int num)
{
	t_ps	*cur;
	t_ps	*tmp;

	cur = *lst;
	while (cur -> next && cur -> num < num)
		cur = cur -> next;
	if (cur -> num == num)
		return (1);
	if (cur -> next == NULL && cur -> num < num)
	{
		tmp = t_ps_new_node(num, NULL, cur);
		cur -> next = tmp;
	}
	else
	{
		tmp = t_ps_new_node(num, cur, cur -> prev);
		cur -> prev -> next = tmp;
		cur -> prev = tmp;
	}
	return (0);
}

int insert_prev(t_ps **lst, int num)
{
    t_ps	*cur;
	t_ps	*tmp;

	cur = *lst;
	while (cur -> prev && cur -> num > num)
		cur = cur -> prev;
	if (cur -> num == num)
		return (1);
	if (cur -> prev == NULL && cur -> num > num)
	{
		tmp = t_ps_new_node(num, cur, NULL);
		cur -> prev = tmp;
	}
	else
	{
		tmp = t_ps_new_node(num, cur -> next, cur);
		cur -> next -> prev = tmp;
		cur -> next = tmp;
	}
	return (0);
}

void	lst_free(t_ps** lst)
{
	t_ps	*cur;

	cur = *lst;
	while (cur -> next)
		cur = cur -> next;
	while (cur -> prev -> prev)
	{
		cur = cur -> prev;
		free(cur -> next);
	}
}

t_ps *lst_init(t_ps **lst, char **argv)
{
    t_ps    *cur;
    int     idx;
    int     num;
    int     err;

    idx = 0;
    *lst = t_ps_new_node(ft_atoi(argv[idx]), NULL, NULL);
    cur = *lst;
    while (argv[++idx])
    {
        num = ft_atoi(argv[idx]);
        if (cur -> num > num)
			err = insert_prev(&cur, num);
        else
            err = insert_next(&cur, num);
		if (err)
		{
			lst_free(lst);
			return (NULL);
		}
    }
	return (cur);
}

