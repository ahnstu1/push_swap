#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

char    *convert(char **argv)
{
    char    *ret;
    char    *tmp;
    int     idx;

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
	if (!cur -> next)
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
	if (cur -> prev == NULL)
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

void	split_free(char **input)
{
    int idx;

    idx = 0;
    while (input[idx])
        idx++;
	while (idx == -1)
		free(input[idx--]);
}

int	err_msg()
{
	write(2, "Error\n", 6);
	return (0);
}

void	lst_test(t_ps** lst)
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

int main(int argc, char **argv)
{
    t_ps  *lst;
    char    *convert_argv;
    char    **split_argv;

	if (argv_check(argv))
		return(err_msg());
    convert_argv = convert(argv);
	printf("\n convert_argv : %s \n", convert_argv);
    if (!convert_argv)
        return(err_msg());
    split_argv = ft_split(convert_argv, ' ');
	printf("\n split_argv \n");
    if (!split_argv)
        return(err_msg());
    free(convert_argv);
    lst = lst_init(&lst, split_argv);
	printf("\n lst \n");
    if (!lst)
		return (err_msg());
	lst_test(&lst);
    split_free(split_argv);
}

//gcc main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_isdigit.c -o push_swap
//gcc -fsanitize=address -g main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_isdigit.c -o push_swap