/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:16:11 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/11 23:31:08 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_map(int value)
{
	int	r;
	int	g;
	int	b;
	int	cycle;

	cycle = 800;
	r = (value * 2) % cycle;
	g = (value * 5) % cycle;
	b = (value * 10) % cycle;
	return (create_trgb(0, r, g, b));
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	int	result;

	result = 0;
	result |= b;
	result |= g << 8;
	result |= r << 16;
	result |= t << 24;
	return (result);
}

int	key_press_m(int keycode, t_mlx_data_m *mlx_data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	return (0);
}

int	key_press_j(int keycode, t_mlx_data_j *mlx_data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	return (0);
}
