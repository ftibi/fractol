/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:51:45 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 11:57:15 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	tuto(void)
{
	ft_putendl("options available : mandelbrot julia");
	exit(0);
}

int		main(int ac, char **av)
{
	t_frac	*frac;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")))
		tuto();
	frac = frac_init(av[1], 0, 0);
	frac_display(frac);
	return (0);
}
