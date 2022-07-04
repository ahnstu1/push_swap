/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:14 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 20:25:56 by hahn             ###   ########.fr       */
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
	if (!ret)
		err_msg();
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
	exit(1);
}

int	main(int argc, char **argv)
{
	t_ps	*lst;
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
	split_free(split_argv);
	if (!lst)
		err_msg();
}
