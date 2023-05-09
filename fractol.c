/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:16:58 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/08 04:31:36 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_atoi(av[1]) == 0)
			mendel();
		else if (ft_atoi(av[1]) == 1)
			julia();
	}
	else
		exit(1);
	return (0);
}
