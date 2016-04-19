/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 12:35:02 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_frac	*recenter(t_frac *frac, int x, int y)
{
	double qx;
	double qy;
	
	qx = (frac->xmax - frac->xmin) / frac->size;
	qy = (frac->ymax - frac->ymin) / frac->size;
//	frac->xmin = (frac->xmax - frac->xmin) * (x / frac->size - 1);
//	frac->xmax = (frac->xmax - frac->xmin) * (x / frac->size);
//	frac->ymin = (frac->ymax - frac->ymin) * (y / frac->size - 1);
//	frac->ymax = (frac->ymax - frac->ymin) * (y / frac->size);
	frac->xmin = ((frac->xmin * x * qx)) * frac->zoom  - qx / 2;
	frac->xmax = ((frac->xmax * x * qx)) * frac->zoom  + qx / 2;
	frac->ymin = ((frac->ymin * y * qy)) * frac->zoom  - qy / 2;
	frac->ymax = ((frac->ymax * y * qy)) * frac->zoom  + qy / 2;
	frac->zoom = 1;
	return (frac);
}

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
		aff_frac(frac);
	}
	frac++;
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_frac *frac)
{
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putstr("pos x : ");
	ft_putnbr(x);
	ft_putstr(" pos y : ");
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 7)
	{
		frac->zoom += 0.5;
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		aff_frac(frac);
	}
	if (button == 6)
	{
		if (frac->zoom <= 0.5)
		{
			frac->zoom = frac->zoom / 2.;
		}
		else
			frac->zoom -= 0.5;
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		aff_frac(frac);
	}
	if (button == 1)
	{
	ft_putendl("ici");
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		aff_frac(frac);
	}
	return (0);
}


