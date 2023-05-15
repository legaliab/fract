/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:16:58 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/14 03:41:12 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mendel", 6) == 0)
			mendel();
		if (ft_strncmp(av[1], "julia", 5) == 0)
			julia();
	}
	else
	{
		ft_printf("    \n\n\n        mendelbrot set: ./fractol mendel\n");
		ft_printf("     \n        julia set: ./fractol julia\n\n\n\n");
		exit(0);
	}
	return (0);
}
