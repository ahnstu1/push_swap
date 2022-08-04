/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:11 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 11:06:34 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_ps
{
	struct s_ps	*prev;
	struct s_ps	*next;
	int			num;
}	t_ps;

typedef struct s_psts
{
	t_ps	*top_a;
	t_ps	*top_b;
	int		size_a;
	int		size_b;
	int		size;
	int		mid;
	int		chunk;
	int		pivot;
	int		pivot1;
	int		pviot_con;
	int		pviot1_con;
}	t_psts;

t_ps	*lst_init(t_ps **lst, char **argv);
void	swap(t_ps *cur);
void	push(t_ps **in, t_ps **out, int size_in, int size_out);
int		pur_finder(t_psts *ts, int pur, int count, int count1);
void	hard_f(t_psts *ts);
void	hard_three(t_psts *ts);
void	hard_two(t_psts *ts);
int		num_vali(char *argv);
void	sa(t_psts *ts);
void	sb(t_psts *ts);
void	pa(t_psts *ts);
void	pb(t_psts *ts);
void	ra(t_psts *ts);
void	rb(t_psts *ts);
void	rra(t_psts *ts);
void	rrb(t_psts *ts);
void	rotate(t_ps **cur);
void	reverse_rotate(t_ps **cur);
t_ps	*t_ps_new_node(int num, t_ps *next, t_ps *prev);
t_ps	*stack_init(t_ps **stack, t_ps *lst, char **argv);
void	stack_b_init(t_psts *top);
t_ps	*stack_a_init(t_ps **stack, t_ps *lst, char **argv);
int		err_msg(void);
int		get_size(t_ps *stack);
void	split_free(char **input);
void	sort(t_psts *ts);
char	*convert(char **argv);
int		argv_check(char	**argv);

#endif