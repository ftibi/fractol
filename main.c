/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:29:59 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 17:32:02 by tfolly           ###   ########.fr       */
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

//int		mandel(int x, int y, void *mlx, void *win)
//{
//	float minx = -2.4;
//	float maxx = 2.4;
//	float miny = -1.5;
//	float maxy = 1.5;
//
//	float rz = 0;
//	float iz = 0;
//	float rc = minx + (maxx - minx)/400 * x;
//	float ic = miny + (maxy - miny)/400 * y;
//	int a = 0;
//	float j = 0;
//	float r = 0;
//
//	int k = 4;
//	
//	while(a < 15)
//	{
//		r = rz;
//		j = iz;
//		rz = r * r + j * j + rc; 
//		iz = 2 * r * j + ic;
//		if (rz * rz + iz * iz > 4)
//		{
//			mlx_pixel_put(mlx, win, x, y, 0x000000);
//			return (0);
//		}
//		a++;
//	}
//	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
//	return (0);
//}

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
	float		size = 400;

	mlx = mlx_init();
	win = mlx_new_window(mlx, size, size, "fractol");

	float xmin = -2;
	float xmax = 2;
	float ymin = -2;
	float ymax = 2;


	float x = 0;
	float y = 0;

	float rc = 1;
	float ic = 1;

	float rz;
	float iz;
	float z2;
	float zc;

	int a;
	int amax = 5;

	int k = 20;

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
			z2 = 0;
			while (a <= amax && z2 < k)
			{
				rz = mfr(rz, iz, rc, ic);
				iz = mfi(rz, iz, rc, ic);
				z2 = rz * rz + iz * iz;
				if (z2 > k)
				{
					mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
				}
				a++;
			}
			if (a == amax)
					mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}



	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}

