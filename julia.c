/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:07:15 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/20 18:08:09 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_draw(t_julia_vars *v, double c_real, double c_imag, int max_iter)
{
	double	temp;

	v->iter = 0;
	while (v->real * v->real + v->imag * v->imag <= 4 && v->iter < max_iter)
	{
		temp = v->real * v->real - v->imag * v->imag + c_real;
		v->imag = 2 * v->real * v->imag + c_imag;
		v->real = temp;
		v->iter++;
	}
	return (v->iter);
}

void	render_fractal(t_mlx_data_j *mlx_data, t_fractal_params *params,
	int max_iter)
{
	t_julia_vars	v;

	mlx_data->image = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->image_data = (int *)mlx_get_data_addr(mlx_data->image,
			&mlx_data->bpp, &mlx_data->size_line, &mlx_data->endian);
	v.y = -1;
	while (++v.y < HEIGHT)
	{
		v.x = -1;
		while (++v.x < WIDTH)
		{
			v.real = (params->x_min + (v.x * (params->x_max - params->x_min))
					/ WIDTH) * mlx_data->scale;
			v.imag = (params->y_min + (v.y * (params->y_max - params->y_min))
					/ HEIGHT) * mlx_data->scale;
			mlx_data->image_data[v.x + v.y * WIDTH] = color_map(julia_draw(&v,
						params->real, params->imag, max_iter));
		}
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->image, 0,
		0);
	mlx_destroy_image(mlx_data->mlx, mlx_data->image);
}

void	update_fractal_params_j(t_fractal_params *params, double zoom_factor,
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

int	mouse_scroll_j(int button, int x, int y, t_mlx_data_j *mlx_data)
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
		mlx_data->scale *= 1.3;
	}
	else if (button == 5)
	{
		mlx_data->scale /= 1.3;
	}
	update_fractal_params_j(mlx_data->params, zoom_factor, center_x, center_y);
	mlx_clear_window(mlx_data->mlx, mlx_data->win);
	render_fractal(mlx_data, mlx_data->params, MAX_ITER);
	return (0);
}

void	julia(t_mlx_data_j *mlx_data, t_fractal_params *params)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "Julia Set");
	params->x_min = -2;
	params->x_max = 2;
	params->y_min = -2;
	params->y_max = 2;
	mlx_data->scale = 1.0;
	mlx_data->params = params;
	render_fractal(mlx_data, params, MAX_ITER);
	mlx_mouse_hook(mlx_data->win, mouse_scroll_j, mlx_data);
	mlx_key_hook(mlx_data->win, key_press_j, mlx_data);
	mlx_hook(mlx_data->win, 17, 0, destroy_notify_m, mlx_data);
	mlx_loop(mlx_data->mlx);
}
