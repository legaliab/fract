/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:25:25 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/17 21:18:51 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burning_ship(t_mlx_data_m *mlx_data, t_mandelbrot_params *params,
		t_vars *v, int max_iter)
{
	double	real;
	double	imag;
	double	temp;
	int		pos;

	real = (params->x_min + (v->x * (params->x_max - params->x_min)) / WIDTH)
		* mlx_data->scale;
	imag = (params->y_min + (v->y * (params->y_max - params->y_min)) / HEIGHT)
		* mlx_data->scale;
	v->r = 0;
	v->i = 0;
	v->iter = -1;
	while (v->r * v->r + v->i * v->i <= 4 && ++v->iter < max_iter)
	{
		temp = v->r * v->r - v->i * v->i + real;
		v->i = 2 * fabs(v->r * v->i) + imag;
		v->r = temp;
	}
	pos = v->x + v->y * WIDTH;
	mlx_data->image_data[pos] = color_map(v->iter);
}

void	render_burning_ship(t_mlx_data_m *mlx_data, t_mandelbrot_params *params,
		int max_iter)
{
	t_vars	v;
	void	*img_ptr;
	int		*img_data;

	img_ptr = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	img_data = (int *)mlx_get_data_addr(img_ptr, &mlx_data->bpp,
			&mlx_data->size_line, &mlx_data->endian);
	mlx_data->image_data = img_data;
	v.y = -1;
	while (++v.y < HEIGHT)
	{
		v.x = -1;
		while (++v.x < WIDTH)
		{
			draw_burning_ship(mlx_data, params, &v, max_iter);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, img_ptr, 0, 0);
	mlx_destroy_image(mlx_data->mlx, img_ptr);
}

void	update_fractal_params_b(t_mandelbrot_params *params, double zoom_factor,
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

int	mouse_scroll_b(int button, int x, int y, t_mlx_data_m *mlx_data)
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
		mlx_data->scale *= 1.1;
	}
	else if (button == 5)
	{
		mlx_data->scale /= 1.1;
	}
	update_fractal_params_b(mlx_data->params, zoom_factor, center_x, center_y);
	mlx_clear_window(mlx_data->mlx, mlx_data->win);
	render_burning_ship(mlx_data, mlx_data->params, MAX_ITER);
	return (0);
}

void	burning_ship(void)
{
	t_mlx_data_m		mlx_data;
	t_mandelbrot_params	params;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT,
			"Burning Ship Fractal");
	params.x_min = -2;
	params.x_max = 2;
	params.y_min = -2;
	params.y_max = 2;
	mlx_data.params = &params;
	mlx_data.scale = 1.0;
	render_burning_ship(&mlx_data, &params, MAX_ITER);
	mlx_mouse_hook(mlx_data.win, mouse_scroll_b, &mlx_data);
	mlx_key_hook(mlx_data.win, key_press_m, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, destroy_notify_m, &mlx_data);
	mlx_loop(mlx_data.mlx);
}
