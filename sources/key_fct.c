/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/25 18:40:07 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		my_key_funct(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	else if (keycode == 15)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac = frac_init(frac->ens, frac->mlx, frac->win);
		frac->aff_frac(frac);
	}
	else if (keycode == 38)
		frac->juliamove = (frac->juliamove) ? 0 : 1;
	else if (keycode == 40)
	{
		frac->juliamove = 0;
		frac->juliax = 0.285;
		frac->juliay = 0.01;
		frac->aff_frac(frac);
	}
	return (0);
}

int		mouse_pos(int x, int y, t_frac *frac)
{
	if (frac->juliamove && frac->aff_frac == aff_frac_julia)
	{
		frac->juliax = x / 500;
		frac->juliay = y / 300;
		frac->aff_frac(frac);
	}
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_frac *frac)
{
	double q;

	q = (frac->xmax - frac->xmin) / frac->size;
	frac->xpoint = (double)x * q + frac->xmin;
	frac->ypoint = (double)y * q + frac->ymin;
	frac->offx = (double)x;
	frac->offy = (double)y;
	if (button == 7)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac->zoom = 2;
		frac = zoom_frac(frac);
		frac->aff_frac(frac);
	}
	else if (button == 6)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac->zoom = 0.5;
		frac = zoom_frac(frac);
		frac->aff_frac(frac);
	}
	return (0);
}
