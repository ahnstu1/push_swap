/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:15:45 by hahn              #+#    #+#             */
/*   Updated: 2022/06/16 00:13:13 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		idx;

	idx = 0;
	output = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!output)
		return (0);
	while (*s1)
		output[idx++] = *(s1++);
	output[idx++] = ' ';
	while (*s2)
		output[idx++] = *(s2++);
	output[idx] = '\0';
	return (output);
}
