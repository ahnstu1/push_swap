/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:14 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 17:19:29 by hahn             ###   ########.fr       */
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

void	lst_test(t_ps **lst)
{
	t_ps	*cur;
	int		idx;

	idx = 0;
	cur = *lst;
	while (cur -> prev)
		cur = cur -> prev;
	while (cur -> next)
	{
		printf("\n idx : %d, num : %d \n", idx++, cur -> num);
		cur = cur -> next;
	}
	printf("\n idx : %d, num : %d \n", idx, cur -> num);
}

int	main(int argc, char **argv)
{
	t_ps	*lst;
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
	lst_test(&lst);
	split_free(split_argv);
}

//gcc main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_isdigit.c -o push_swap
//gcc -fsanitize=address -g main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_isdigit.c -o push_swap
