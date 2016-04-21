/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:29:59 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/21 17:43:32 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "mlx.h"
#define PointerMotionMask (1L<<6)	
#define MotionNotify 6	

#define EnterNotify 7//entre ou sort de la fenetre, a utiliser ou pas ?
#define LeaveNotify 8		

int		mouse_pos(void *mlx, void *win)
{
	int x,y;

	XQueryPointer(mlx, win, win, win, root_x_return, root_y_return, 
			                     &x, &y, 0)

	ft_putnbr(x);
	ft_putchar('\n');
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		my_key_funct(int keycode)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	return (0);
}

int		my_mouse_funct(int button, int x, int y, void *param)
{
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putstr("pos x : ");
	ft_putnbr(x);
	ft_putstr(" pos y : ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		main()
{
	int x_event, x_mask;

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
	float amax = 50;

	float k = 4;
	float rz2;

	double zoom = 1;

	mlx = mlx_init();
	win = mlx_new_window(mlx, size, size, "fractol");
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			rz = xmin + x * (xmax - xmin) / size * zoom;
			iz = ymin + y * (ymax - ymin) / size * zoom;
			//ensemble de mandelbrot
			//rc = rz;
			//ic = iz;
			//ensemble de julia
			rc = 0.285;
			ic = 0.01;
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
	mlx_mouse_hook(win, my_mouse_funct, 0);
	mlx_hook(win, MotionNotify, PointerMotionMask, mouse_pos, 0);
	mlx_loop(mlx);
	return (0);
}
