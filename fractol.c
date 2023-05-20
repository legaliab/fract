/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:16:58 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/17 01:43:07 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx_data_j		mlx_data;
	t_fractal_params	params;

	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mendel", 6) == 0)
			mendel();
		else if (ft_strncmp(av[1], "burning", 7) == 0)
			burning_ship();
	}
	if (ac == 4)
	{
		params.real = ft_atod(av[2]);
		params.imag = ft_atod(av[3]);
		if (ft_strncmp(av[1], "julia", 5) == 0)
			julia(&mlx_data, &params);
	}
	else
	{
		ft_printf("    \n\n\n        mendelbrot set: ./fractol mendel\n");
		ft_printf("    \n        burning ship set: ./fractol burning\n");
		ft_printf("     \n        julia set: ./fractol julia arg1 arg2\n\n\n\n");
		exit(0);
	}
	return (0);
}
