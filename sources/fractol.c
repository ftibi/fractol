/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:51:45 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 20:38:17 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	tuto(void)
{
	ft_putendl("USAGE : ./fractol <parameter>");
	ft_putendl("parameters available : mandelbrot julia dragon");
	exit(0);
}

int			main(int ac, char **av)
{
	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") &&
				ft_strcmp(av[1], "julia") && (ft_strcmp(av[1], "dragon"))))
		tuto();
	manuel();
	frac_display(av[1]);
	return (0);
}
