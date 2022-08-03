/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:14 by hahn              #+#    #+#             */
/*   Updated: 2022/08/04 08:18:52 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*lst_front(t_ps *lst)
{
	t_ps	*ret;

	ret = lst;
	while (ret -> prev)
		ret = ret -> prev;
	return (ret);
}

t_psts	*ts_init(t_ps *stack)
{
	t_psts	*ts;

	ts = (t_psts *)malloc(sizeof(t_psts) * 1);
	if (!ts)
		return (0);
	ts -> top_a = stack;
	ts -> top_b = NULL;
	ts -> size_a = get_size(stack);
	ts -> size_b = 0;
	ts -> size = ts -> size_a;
	ts -> chunk = ts -> size_a / 50 + 5;
	ts -> mid = ts -> size_a / 2;
	ts -> pivot = ts -> mid + ts -> chunk;
	ts -> pivot1 = ts -> mid - ts -> chunk;
	ts -> pviot_con = ts -> chunk;
	ts -> pviot1_con = ts -> chunk;
	return (ts);
}

int	main(int argc, char **argv)
{
	t_ps	*lst;
	t_ps	*stack_a;
	t_psts	*ts;
	char	*convert_argv;
	char	**split_argv;

	if (argc < 2 || argv_check(argv))
		err_msg();
	if (argc == 2 && num_vali(argv[1]))
		exit(0);
	convert_argv = convert(argv);
	split_argv = ft_split(convert_argv, ' ');
	if (!split_argv)
		err_msg();
	free(convert_argv);
	lst = lst_init(&lst, split_argv);
	if (!lst)
		err_msg();
	stack_a_init(&stack_a, lst_front(lst), split_argv);
	ts = ts_init(stack_a);
	split_free(split_argv);
	sort(ts);
	exit(0);
}
