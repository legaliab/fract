/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melbrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:00:44 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/09 21:56:02 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_mlx_data_m *mlx_data, t_mandelbrot_params *params,
		t_vars *v)
{
	double	real;
	double	imag;
	double	r2;
	double	i2;

	real = params->x_min + (v->x * (params->x_max - params->x_min)) / WIDTH;
	imag = params->y_min + (v->y * (params->y_max - params->y_min)) / HEIGHT;
	v->r = 0;
	v->i = 0;
	v->iter = -1;
	r2 = 0;
	i2 = 0;
	while (r2 + i2 <= 4 && ++v->iter < MAX_ITER)
	{
		v->i = 2 * v->r * v->i + imag;
		v->r = r2 - i2 + real;
		r2 = v->r * v->r;
		i2 = v->i * v->i;
	}
	mlx_pixel_put(mlx_data->mlx, mlx_data->win, v->x, v->y, color_map(v->iter));
}

void	render_mandelbrot(t_mlx_data_m *mlx_data, t_mandelbrot_params *params)
{
	t_vars	v;

	v.y = -1;
	while (++v.y < HEIGHT)
	{
		v.x = -1;
		while (++v.x < WIDTH)
		{
			draw_mandelbrot(mlx_data, params, &v);
		}
	}
}

void	update_fractal_params_m(t_mandelbrot_params *params, double zoom_factor,
		double center_x, double center_y)
{
	double	width;
	double	height;

	width = (params->x_max - params->x_min);
	height = (params->y_max - params->y_min);
	params->x_min = center_x - (width / (2 * zoom_factor));
	params->x_max = center_x + (width / (2 * zoom_factor));
	params->y_min = center_y - (height / (2 * zoom_factor));
	params->y_max = center_y + (height / (2 * zoom_factor));
}

int	mouse_scroll_m(int button, int x, int y, t_mlx_data_m *mlx_data)
{
	double	zoom_factor;
	double	center_x;
	double	center_y;

	zoom_factor = 1.0;
	center_x = mlx_data->params->x_min + (x * (mlx_data->params->x_max
				- mlx_data->params->x_min)) / WIDTH;
	center_y = mlx_data->params->y_min + (y * (mlx_data->params->y_max
				- mlx_data->params->y_min)) / HEIGHT;
	if (button == 4)
	{
		zoom_factor = 1.1;
	}
	else if (button == 5)
	{
		zoom_factor = 1 / 1.1;
	}
	update_fractal_params_m(mlx_data->params, zoom_factor, center_x, center_y);
	render_mandelbrot(mlx_data, mlx_data->params);
	return (0);
}

void	mendel(void)
{
	t_mlx_data_m		mlx_data;
	t_mandelbrot_params	params;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT,
			"Mandelbrot Set");
	params.x_min = -2;
	params.x_max = 1;
	params.y_min = -1;
	params.y_max = 1;
	mlx_data.params = &params;
	render_mandelbrot(&mlx_data, &params);
	mlx_mouse_hook(mlx_data.win, mouse_scroll_m, &mlx_data);
	mlx_key_hook(mlx_data.win, key_press_m, &mlx_data);
	mlx_loop(mlx_data.mlx);
}
