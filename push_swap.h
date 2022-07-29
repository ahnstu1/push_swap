/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:11 by hahn              #+#    #+#             */
/*   Updated: 2022/07/30 03:09:47 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_ps
{
	struct s_ps	*prev;
	struct s_ps	*next;
	int			num;
}	t_ps;

typedef	struct s_pstp
{
	t_ps	*a_top;
	t_ps	*b_top;
	int		size_a;
	int		size_b;
}	t_pstp;


void 	lst_test(t_ps *l);
//
t_ps	*lst_init(t_ps **lst, char **argv);
void	swap(t_ps *cur);
void	push(t_ps *in, t_ps *out, int size_in, int size_out);
void	rotate(t_ps *cur);
void	sa(t_pstp *top);
void	sb(t_pstp *top);
void	pa(t_pstp *top);
void	pb(t_pstp *top);
t_ps	*reverse_rotate(t_ps *cur);
t_ps	*t_ps_new_node(int num, t_ps *next, t_ps *prev);
t_ps	*stack_init(t_ps **stack, t_ps *lst, char **argv);
void	*stack_b_init(t_pstp *top, int size);
t_ps	*stack_a_init(t_ps **stack, t_ps *lst, char **argv);
int		err_msg(void);
int		get_size(t_ps *stack);
void	split_free(char **input);
void    sort(t_ps *stack_a);
char	*convert(char **argv);
int		argv_check(char	**argv);

#endif