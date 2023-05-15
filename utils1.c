/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:46:52 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/12 02:02:00 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_notify_m(t_mlx_data_m *mlx_data)
{
	close_window_m(mlx_data);
	return (0);
}

int	close_window_m(t_mlx_data_m *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
	return (0);
}

int	destroy_notify_j(t_mlx_data_m *mlx_data)
{
	close_window_j(mlx_data);
	return (0);
}

int	close_window_j(t_mlx_data_m *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
	return (0);
}

// double	atod(const char *str)
// {
// 	double	result;
// 	double	sign;
// 	bool	decimal_point;
// 	int		decimal_places;
// 	int		i;

// 	result = 0.0;
// 	sign = 1.0;
// 	decimal_point = false;
// 	decimal_places = 0;
// 	if (*str == '-' && ++str)
// 		sign = -1.0;
// 	else if (*str == '+')
// 		str++;
// 	while (*str)
// 	{
// 		if (*str == '.')
// 		{
// 			if (!decimal_point)
// 				decimal_point = true;
// 			else
// 				return (0.0);
// 		}
// 		else if (isdigit(*str))
// 		{
// 			if (decimal_point)
// 				decimal_places++;
// 			result = result * 10.0 + (*str - '0');
// 		}
// 		else
// 			return (0.0);
// 		str++;
// 	}
// 	result *= sign;
// 	i = -1;
// 	while (++i < decimal_places)
// 		result /= 10.0;
// 	return (result);
// }
