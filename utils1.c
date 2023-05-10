/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:46:52 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/10 16:49:36 by alabdull         ###   ########.fr       */
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
