/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:59:42 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	frac_reset(t_frac *frac)
{
	frac->xmin = -2.;
	frac->xmax = 2.;
	frac->ymin = -2.;
	frac->ymax = 2.;
	frac->rc = 0;
	frac->ic = 0;
	frac->rz = 0;
	frac->iz = 0;
	frac->z2 = 0;
	frac->rz2 = 0;
	frac->amax = 50;
	if (!ft_strcmp(frac->ens, "dragon"))
		frac->amax = 15;
	frac->a = 0;
	frac->k = 10;
	frac->zoom = 1;
	frac->offx = 0;
	frac->offy = 0;
	frac->juliax = 0.285;
	frac->juliay = 0.01;
	frac->juliamove = 1;
	frac->xpoint = 0;
	frac->ypoint = 0;
	frac->color = 0xFFFFFF;
}

int		my_key_funct(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	else if (keycode == 15)
	{
		frac_reset(frac);
		mlx_clear_window(frac->mlx, frac->win);
		frac->aff_frac(frac);
	}
	else if (keycode == 38)
		frac->juliamove = (frac->juliamove) ? 0 : 1;
	else if (keycode == 40)
	{
		frac_reset(frac);
		frac->juliamove = 0;
		mlx_clear_window(frac->mlx, frac->win);
		frac->aff_frac(frac);
	}
	arrow_keys(frac, keycode);
	change_iter(frac, keycode);
	change_color(frac, keycode);
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
	if (button == 7 || button == 4)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac->zoom = 2;
		frac = zoom_frac(frac);
		frac->aff_frac(frac);
	}
	else if (button == 6 || button == 5)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac->zoom = 0.5;
		frac = zoom_frac(frac);
		frac->aff_frac(frac);
	}
	return (0);
}
