/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:29:59 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/17 17:16:43 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		my_key_funct(int keycode)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	return (0);
}

int		main()
{
	void 	*mlx;
	void 	*win;
	float	size = 800;
	double xmin = -2;
	double xmax = 2;
	double ymin = -2;
	double ymax = 2;

	double x;
	double y;

	double rc;
	double ic;

	double rz;
	double iz;
	double z2;

	float a;
	float amax = 20;

	float k = 4;
	float rz2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, size, size, "fractol");
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			rz = xmin + x * (xmax - xmin) / size;
			iz = ymin + y * (ymax - ymin) / size;
			rc = rz;
			ic = iz;
			z2 = rz * rz + iz * iz;
			a = 0;
			while (a <= amax && z2 <= k)
			{
				rz2 = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * rz2 * iz + ic;
				z2 = rz * rz + iz * iz;
				if (z2 >= k)
					mlx_pixel_put(mlx, win, x, y, a / amax * 0xFFFFFF);
				a++;
			}
		//	if (a == amax)
		//			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
