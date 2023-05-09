/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:45 by alabdull          #+#    #+#             */
/*   Updated: 2023/04/08 22:22:10 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_iswhitespaces(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int			i;
	int			n;
	int			result;

	i = -1;
	n = 1;
	result = 0;
	while (str[i] && ft_iswhitespaces(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[++i]))
	{
		result = result * 10 + (str[i] - '0');
	}
	return (result * n);
}
