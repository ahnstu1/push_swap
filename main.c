#include "libft/libft.h"
#include <stdio.h>

void    swap(int num_arr[], int top)
{
    int tmp;

    tmp = num_arr[top];
    num_arr[top] = num_arr[top + 1];
    num_arr[top + 1] = tmp;
}

void    push(int num_arr_out[], int num_arr_in[], int *out_top, int *in_top)
{
    num_arr_in[*++in_top] = num_arr_out[*out_top--];
}

void    rotate(int num_arr[], int top)
{
    int idx;
    int tmp;
    int temp;

    idx = 0;
    tmp = num_arr[idx];
    while (idx < top)
    {
        temp = num_arr[idx + 1];
        num_arr[idx + 1] = tmp;
        tmp = temp;
        idx++;
    }
    num_arr[0] = tmp;
}

void    reverse_rotate(int num_arr[], int top)
{
    int idx;
    int tmp;
    int temp;

    idx = top;
    tmp = num_arr[idx];
    while (idx > 0)
    {
        temp = num_arr[idx - 1];
        num_arr[idx - 1] = tmp;
        tmp = temp;
        idx--;
    }
    num_arr[top] = tmp;
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        s1++;
        s2++;
        if (!*s1 && !*s2)
            return (0);
    }
    if (!*s1 && !*s2)
        return (1);
    return (0);
}

int err_check(char **split_argv)
{
    int     idx;
    int     c_idx;
    int     num;

    idx = 0;
    while (split_argv[idx] != NULL)
    {
        num = ft_atoi(split_argv[idx]);
        if (ft_strlen(split_argv[idx]) != ft_strlen(ft_itoa(num)))
            return (0);
        c_idx = idx + 1;
        while(split_argv[c_idx] != NULL)
        {
            if (ft_strcmp(split_argv[idx], split_argv[c_idx]))
                return (0);
            c_idx++;
        }
        idx++;
    }
    return (idx);
}

void arr_init(int *num_arr, char **argv, int *top)
{
    while (argv[++*top] != NULL)
        num_arr[*top] = ft_atoi(argv[*top]);
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
        ret = ft_strjoin(ret, " ");
        free(tmp);
        tmp = ret;
        ret = ft_strjoin(ret, argv[idx]);
        free(tmp);
    }
    return (ret);
}

int main(int argc, char **argv)
{
    int     *num_arr_a;
    int     *num_arr_b;
    int     top_a;
    int     top_b;
    int     size;
    char    *convert_argv;
    char    **split_argv;

    convert_argv = convert(argv);
    split_argv = ft_split(convert_argv, ' ');
    size = err_check(split_argv);
    if (!size)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    num_arr_a = (int *)malloc(sizeof(int) * size);
    top_a = -1;
    num_arr_b = (int *)malloc(sizeof(int) * size);
    top_b = -1;
    arr_init(num_arr_a, split_argv, &top_a);
}

//gcc main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c
//gcc -fsanitize=address -g main.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_itoa.c