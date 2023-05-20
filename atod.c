/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:19:26 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/20 18:06:52 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static double	ft_atod_frac(const char *str, double sign, double result, int i)
{
	double	frac_part;
	double	frac_divisor;

	frac_part = 0;
	frac_divisor = 10;
	while (str[i] && ft_isdigit(str[i]))
	{
		frac_part += (str[i] - '0') / frac_divisor;
		frac_divisor *= 10;
		++i;
	}
	return (sign * (result + frac_part));
}

double	ft_atod(const char *str)
{
	double	sign;
	double	result;
	int		i;

	sign = 1.0;
	i = 0;
	result = 0.0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		++i;
	}
	if (str[i] == '.')
		++i;
	return (ft_atod_frac(str, sign, result, i));
}
