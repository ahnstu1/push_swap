/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:14 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 20:04:55 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_check(char	**argv)
{
	int	idx;
	int	check;

	idx = 1;
	while (argv[idx])
	{
		check = 0;
		while (!ft_isdigit(argv[idx][check]) && argv[idx][check])
			check++;
		if (!argv[idx][check])
			return (1);
		idx++;
	}
	return (0);
}

char	*convert(char **argv)
{
	char	*ret;
	char	*tmp;
	int		idx;

	idx = 1;
	ret = ft_strdup(argv[1]);
	while (argv[++idx] != NULL)
	{
		tmp = ret;
		ret = ft_strjoin(ret, argv[idx]);
		free(tmp);
	}
	return (ret);
}

void	split_free(char **input)
{
	int	idx;

	idx = 0;
	while (input[idx])
		idx++;
	while (idx == -1)
		free(input[idx--]);
}

int	err_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

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

t_ps	*lst_head_finder(t_ps *lst)
{
	t_ps *ret;

	ret = lst;
	while (ret -> prev)
		ret = ret -> prev;
	return (ret);
}

int	main(int argc, char **argv)
{
	t_ps	*lst;
	t_ps	*lst_head_testing;
	t_ps	*new_lst_test = NULL;
	char	*convert_argv;
	char	**split_argv;

	if (argc < 2 || argv_check(argv))
		return (err_msg());
	convert_argv = convert(argv);
	if (!convert_argv)
		return (err_msg());
	split_argv = ft_split(convert_argv, ' ');
	if (!split_argv)
		return (err_msg());
	free(convert_argv);
	lst = lst_init(&lst, split_argv);
	if (!lst)
		return (err_msg());
	lst_head_testing = lst_head_finder(lst);
	lst_test(lst_head_testing);
	lst_head_testing = swap(lst_head_testing);
	printf("\n swap complete \n");
	lst_test(lst_head_testing);
	printf("\n swap test complete \n");
	lst_head_testing = push(&new_lst_test, lst_head_testing);
	printf("\n push complete \n");
	lst_test(lst_head_testing);
	printf("\n push lst test complete \n");
	printf("\n new lst = %p\n", new_lst_test);
	lst_test(new_lst_test);
	printf("\n push new lst test complete \n");
	lst_head_testing = rotate(lst_head_testing);
	printf("\n rotate complete \n");
	lst_test(lst_head_testing);
	printf("\n rotate test complete \n");
	lst_head_testing = reverse_rotate(lst_head_testing);
	printf("\n reverse_rotate complete \n");
	lst_test(lst_head_testing);
	printf("\n reverse_rotate test complete \n");
	split_free(split_argv);
}
