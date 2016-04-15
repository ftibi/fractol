/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:29:59 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 18:26:11 by tfolly           ###   ########.fr       */
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

float mfr(float rz, float iz, float rc, float ic)
{
	return (rz * rz - iz * iz + rc);
}

float mfi(float rz, float iz, float rc, float ic)
{
	return (2 * rz * iz + ic);
}

int		main(int ac, char **av)
{
	void *mlx;
	void *win;
	float		size = 800;

	mlx = mlx_init();
	win = mlx_new_window(mlx, size, size, "fractol");

	double xmin = -2;
	double xmax = 2;
	double ymin = -2;
	double ymax = 2;


	double x = 0;
	double y = 0;

	double rc = 1;
	double ic = 1;

	double rz;
	double iz;
	double z2;

	int a;
	int amax = 20;

	int k = 5;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			rz = xmin + (xmax - xmin) / size * x;
			iz = ymin + (ymax - ymin) / size * y;
			rc = rz;
			ic = iz;
			a = 0;
			z2 = rz * rz + iz * iz;
			while (a <= amax && z2 <= k)
			{
				rz = mfr(rz, iz, rc, ic);
				iz = mfi(rz, iz, rc, ic);
				z2 = rz * rz + iz * iz;
				if (z2 >= k)
				{
					mlx_pixel_put(mlx, win, x, y, a * ft_pow(2, 10) / amax);//0xFFFFFF);
				}
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

