/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:54:31 by hahn              #+#    #+#             */
/*   Updated: 2022/07/30 01:39:57 by hahn             ###   ########.fr       */
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
