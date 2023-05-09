/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:07:15 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/09 21:45:06 by alabdull         ###   ########.fr       */
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

	v.y = -1;
	while (++v.y < HEIGHT)
	{
		v.x = -1;
		while (++v.x < WIDTH)
		{
			v.real = params->x_min + (v.x * (params->x_max - params->x_min))
				/ WIDTH;
			v.imag = params->y_min + (v.y * (params->y_max - params->y_min))
				/ HEIGHT;
			mlx_pixel_put(mlx_data->mlx, mlx_data->win, v.x, v.y,
				color_map(julia_draw(&v, params->real, params->imag,
						max_iter)));
		}
	}
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
		zoom_factor = 1.1;
	}
	else if (button == 5)
	{
		zoom_factor = 1 / 1.1;
	}
	update_fractal_params_j(mlx_data->params, zoom_factor, center_x, center_y);
	render_fractal(mlx_data, mlx_data->params, MAX_ITER);
	return (0);
}

void	julia(void)
{
	t_mlx_data_j		mlx_data;
	t_fractal_params	params;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT, "Julia Set");
	params.x_min = -2;
	params.x_max = 1;
	params.y_min = -1;
	params.y_max = 1;
	params.real = -0.8;
	params.imag = 0.156;
	mlx_data.params = &params;
	render_fractal(&mlx_data, &params, MAX_ITER);
	mlx_mouse_hook(mlx_data.win, mouse_scroll_j, &mlx_data);
	mlx_key_hook(mlx_data.win, key_press_j, &mlx_data);
	mlx_loop(mlx_data.mlx);
}
