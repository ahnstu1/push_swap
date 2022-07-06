/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:14 by hahn              #+#    #+#             */
/*   Updated: 2022/07/06 11:18:22 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	lst_test(t_ps *lst)
{
	int		idx;

	idx = 0;
	if (lst -> prev == NULL)
		printf("\n lst -> prev is NULL \n");
	while (lst -> next)
	{
		printf("\n idx : %d, num : %d \n", idx++, lst -> num);
		lst = lst -> next;
	}
	printf("\n idx : %d, num : %d \n", idx, lst -> num);
	printf("\n reverse start \n");
	while (lst -> prev)
	{
		printf("\n idx : %d, num : %d \n", idx--, lst -> num);
		lst = lst -> prev;
	}
	printf("\n idx : %d, num : %d \n", idx, lst -> num);
}
*/

t_ps	*lst_front(t_ps *lst)
{
	t_ps	*ret;

	ret = lst;
	while (ret -> prev)
		ret = ret -> prev;
	return (ret);
}

int	main(int argc, char **argv)
{
	t_ps	*lst;
	t_ps	*stack_a;
	char	*convert_argv;
	char	**split_argv;

	if (argc < 2 || argv_check(argv))
		err_msg();
	convert_argv = convert(argv);
	split_argv = ft_split(convert_argv, ' ');
	if (!split_argv)
		err_msg();
	free(convert_argv);
	lst = lst_init(&lst, split_argv);
	//lst_test(lst);
	if (!lst)
		err_msg();
	stack_init(&stack_a, lst_front(lst), split_argv);
	//lst_test(stack_a);
	split_free(split_argv);
}
