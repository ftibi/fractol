/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:24:02 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/25 16:31:11 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double ft_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_frac	*zoom_frac(t_frac *frac)
{
	double	q;

	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	frac->xmin = frac->xpoint - frac->offx * q * frac->zoom;
	frac->xmax = frac->xmin + q * frac->size * frac->zoom;
	frac->ymin = frac->ypoint - frac->offy * q * frac->zoom;
	frac->ymax = frac->ymin + q * frac->size * frac->zoom;
	if (frac->zoom == 0.5)
		frac->amax += 10;
	else
		frac->amax -= 10;
	frac->zoom = 1;
	return (frac);
}

void	aff_frac_mandel(void *frac2)
{
	double	x;
	double	y;
	int		a;
	t_frac	*frac = (t_frac*)frac2;
	double	q;
	

	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	x = 0;
	ft_putnbr(frac->offx);
	ft_putchar('\n');
	ft_putnbr(frac->offy);
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = (frac->xmin + (x) * q);
			frac->iz = (frac->ymin + (y) * q);
			//param de depart pour mandel
			frac->rc = frac->rz;
			frac->ic = frac->iz;
			frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
			a = 0;
			while (a <= frac->amax && frac->z2 <= frac->k)
			{
				frac->rz2 = frac->rz;
				frac->rz = frac->rz * frac->rz - frac->iz * frac->iz + frac->rc;
				frac->iz = 2 * frac->rz2 * frac->iz + frac->ic;
				frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
				if (frac->z2 >= frac->k)
					mlx_pixel_put(frac->mlx, frac->win, x, y, a / frac->amax * 0xFFFFFF);
				a++;
			}
			if (a == frac->amax)
					mlx_pixel_put(frac->mlx, frac->win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}



void	aff_frac_julia(void *frac2)
{
	double	x;
	double	y;
	int		a;
	t_frac	*frac = (t_frac*)frac2;
	double	q = ft_abs((frac->xmax - frac->xmin) / frac->size);

	x = 0;
	ft_putnbr(frac->offx);
	ft_putchar('\n');
	ft_putnbr(frac->offy);
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = (frac->xmin + (x) * q);
			frac->iz = (frac->ymin + (y) * q);
			//param de depart julia
			frac->rc = frac->juliax;
			frac->ic = frac->juliay;
			frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
			a = 0;
			while (a <= frac->amax && frac->z2 <= frac->k)
			{
				frac->rz2 = frac->rz;
				frac->rz = frac->rz * frac->rz - frac->iz * frac->iz + frac->rc;
				frac->iz = 2 * frac->rz2 * frac->iz + frac->ic;
				frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
				if (frac->z2 >= frac->k)
					mlx_pixel_put(frac->mlx, frac->win, x, y, a / frac->amax * 0xFFFFFF);
				a++;
			}
			if (a == frac->amax)
					mlx_pixel_put(frac->mlx, frac->win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void		frac_display(char *str)
{
	t_frac *frac;

	frac = frac_init(str, 0 , 0);
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, frac->size, frac->size, "fractol");
	frac->aff_frac(frac);
	mlx_key_hook(frac->win, my_key_funct, frac);
	mlx_mouse_hook(frac->win, my_mouse_funct, frac);
	mlx_hook(frac->win, MotionNotify, PointerMotionMask, mouse_pos, frac);
	mlx_loop(frac->mlx);
}
