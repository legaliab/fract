/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:36:23 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/15 18:32:16 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_mandelbrot_params
{
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				zoom_factor;
	double				center_x;
	double				center_y;
}						t_mandelbrot_params;

typedef struct s_fractal_params
{
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				real;
	double				imag;
	double				zoom_factor;
	double				center_x;
	double				center_y;
}						t_fractal_params;

typedef struct s_mlx_data_m
{
	void				*mlx;
	void				*win;
	t_mandelbrot_params	*params;
	double				scale;
	int					*image_data;
	int					endian;
	int					bpp;
	int					size_line;
}						t_mlx_data_m;

typedef struct s_mlx_data_j
{
	void				*mlx;
	void				*win;
	t_fractal_params	*params;
	double				scale;
}						t_mlx_data_j;

typedef struct s_vars
{
	int					y;
	int					x;
	int					iter;
	double				r;
	double				i;
}						t_vars;

typedef struct s_julia_vars
{
	int					y;
	int					x;
	int					iter;
	double				real;
	double				imag;
}						t_julia_vars;

# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 100

int						color_map(int value);
int						create_trgb(unsigned char t, unsigned char r,
							unsigned char g, unsigned char b);
int						key_press_m(int keycode, t_mlx_data_m *mlx_data);
int						key_press_j(int keycode, t_mlx_data_j *mlx_data);
int						destroy_notify_m(t_mlx_data_m *mlx_data);
int						close_window_m(t_mlx_data_m *mlx_data);
int						destroy_notify_j(t_mlx_data_m *mlx_data);
int						close_window_j(t_mlx_data_m *mlx_data);
void					mendel(void);
void					julia(void);

#endif