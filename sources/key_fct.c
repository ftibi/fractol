/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 18:20:46 by tfolly           ###   ########.fr       */
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
	ft_putstr("keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 15)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac = frac_init(frac->ens, frac->mlx, frac->win);
		frac->aff_frac(frac);
	}
	if (keycode == 38)
	{
		frac->juliamove = (frac->juliamove) ? 0 : 1;
	}
	return (0);
}

int		mouse_pos(int x, int y, t_frac *frac)
{
//	frac++;
	x++;
	y++;
	// ici il faudrait faire une equation qui depend de la pos du curseur sur lecran
	if (frac->juliamove && frac->aff_frac == aff_frac_julia)
	{
		frac->juliax += 0.01;
		frac->juliay += 0.01;
		if (frac->juliax > 1)
		{
			frac->juliax = 0.285;
			frac->juliay = 0.01;
		}
		frac->aff_frac(frac);

	}
	ft_putnbr(x); ft_putchar(':'); ft_putnbr(y);
//	ft_putendl(" on a encore bouge");
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_frac *frac)
{
	frac->offx = (double)x;
	frac->offy = (double)y;
	printf(" mouse %f %d %d  %f %f\n", frac->zoom,x, y, frac->offx, frac->offy);
	if (button == 7)
	{
		mlx_clear_window(frac->mlx, frac->win);
		if (frac->zoom <= 0.5)
			frac->zoom *= 2;
		else
			frac->zoom += 0.5;
		frac->aff_frac(frac);
	}
	else if (button == 6)
	{
		
		mlx_clear_window(frac->mlx, frac->win);
		frac->zoom = frac->zoom / 2.;
		frac->aff_frac(frac);
	}
	else if (button == 1)
	{
	//	frac->zoom *= 2;
		ft_putnbr(frac->zoom);
		ft_putchar('\n');
		mlx_clear_window(frac->mlx, frac->win);
		frac->aff_frac(frac);
	}
	return (0);
}
