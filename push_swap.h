/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:11 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 19:46:19 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_ps
{
    struct s_ps *prev;
    struct s_ps *next;
    int         num;
}   t_ps;

t_ps	*lst_init(t_ps **lst, char **argv);
t_ps	*swap(t_ps *cur);
t_ps	*push(t_ps *in, t_ps *out);
t_ps	*rotate(t_ps *cur);
t_ps	*reverse_rotate(t_ps *cur);
t_ps	*t_ps_new_node(int num, t_ps *next, t_ps *prev);

#endif